#include <bits/stdc++.h>
using namespace std;

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
}

Node getJson(string&, int&);

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
