#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
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
=======
string doc;
int n, m;
struct Node {
	bool type;
	string val;
	map<string, Node> obj;
	Node() {}
	Node(string s) : type(false), val(s) { }
};

string getStr(string& str, int& i) {
	i++;
	string ret;
	while (str[i] != '\"') {
		if (str[i] == '\\')	ret += str[i + 1], i += 2;
		else ret += str[i++];
	}
	i++;
	return ret;
>>>>>>> 557e9887ee473fbd7fdfc3aae59f5275fc7d3856
}

Node getJson(string&, int&);

<<<<<<< HEAD
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
=======
void getItem(Node& json, string& str, int& i) {
	auto key = getStr(str, i);
	while (str[i] != ':')	i++;
	i++;
	while (str[i] != '\"' && str[i] != '{') {
		i++;
	}
	if (str[i] == '\"') {
		json.obj[key] = Node(getStr(str, i));
	} else {
		json.obj[key] = getJson(str, i);
	}
}

Node getJson(string& str, int& i) {
	Node ret;
	ret.type = true;
	while (str[i] != '{')	i++;
	i++;
	while (str[i] != '}') {
		if (str[i] == '\"') {
			getItem(ret, str, i);
		}
		else	i++;
	}
	i++;
	return ret;
}

void query(Node node, vector<string>& strs) {
	for (auto& str : strs) {
		if (!node.type || !node.obj.count(str)) {
			puts("NOTEXIST");
			return;
		}
		auto t = node.obj[str];
		node = t;
	}
	if (node.type == false) {
		printf("STRING %s\n", node.val.c_str());
	} else {
		puts("OBJECT");
	}
}

int main() {
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0 ; i < n; i++) {
		string line;
		getline(cin, line);
		doc += line;
	}
	int k = 0;
	auto json = getJson(doc, k);
	while (m--) {
		vector<string> elems;
		string line;
		getline(cin, line);
		for (int i = 0; i < line.size(); i++) {
			int j = i + 1;
			while (j < line.size() && line[j] != '.')	j++;
			elems.push_back(line.substr(i, j - i));
			i = j;
		}
		query(json, elems);
	}
	return 0;
} 
>>>>>>> 557e9887ee473fbd7fdfc3aae59f5275fc7d3856
