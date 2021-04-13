#include <bits/stdc++.h>
using namespace std;

struct Node {
    int type;
    string str;
    map<string, Node> obj;
    Node() {}
    Node(string s) : str(s), type(0) {};
};
int n, m;

string getStr(string& str, int& k) {
    k++;
    string ret;
    while (str[k] != '\"') {
        if (str[k] == '\\') ret += str[k + 1], k += 2;
        else ret += str[k++];
    }
    k++;
    return ret;
}

Node getJson(string&, int&);

void getKv(Node& obj, string& str, int& k) {
    auto key = getStr(str, k);
    while (str[k] != ':')  k++;
    k++;
    while (str[k] != '\"' && str[k] != '{') k++;
    if (str[k] == '\"') obj.obj[key] = Node(getStr(str, k));
    else obj.obj[key] = getJson(str, k);
}

Node getJson(string &str, int& k) {
    Node ret;
    ret.type = 1;
    while(str[k] != '{')    k++;
    k++;
    while (str[k] != '}') {
        if (str[k] == '\"') getKv(ret, str, k);
        else    k++;
    }
    k++;
    return ret;
}

void query(Node obj, vector<string>& qs) {
    for (auto &s : qs) {
        if (obj.type == 0 || !obj.obj.count(s)) {
            puts("NOTEXIST");
            return;
        }
        auto temp = obj.obj[s];
        obj = temp;
    }
    if (obj.type == 0)  printf("STRING %s\n", obj.str.c_str());
    else    puts("OBJECT");
}

int main() {
    scanf("%d%d", &n, &m);
    getchar();
    string str, s;
    while (n--) {
        getline(cin, s);
        str += s;
    }
    int k = 0;
    auto json = getJson(str, k);
    while (m--) {
        getline(cin, s);
        vector<string> qs;
        for (int i = 0; i < s.size(); i++) {
            int j = i + 1;
            while (j < s.size() && s[j] != '.') j++;
            qs.push_back(s.substr(i, j - i));
            i = j;
        }
        query(json, qs);
    }
    return 0;
}