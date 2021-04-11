#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
const int MAXN = 2000010;
char op[2], str[110];
int n, cnt;
struct Node {
	string name;
	int id, type;	// 0 文件夹 1 文件 
	LL ld, lr;
	LL size;
	map<string, int> sons;
	Node(const string& nm) : name(nm) {} 
	Node(const string& nm, int i, int t, LL sz) : name(nm), id(i), type(t), size(sz) {}
};
vector<Node> a;
//set<Node> sons[MAXN];

vector<string> parseStr(char* path) {
	vector<string> ret;
//	ret.push_back("x");
	for (int i = 1; i < strlen(path); i++) {
		int j = i + 1;
		string s;
		while (j < strlen(path) && path[j] != '/') {
			s += path[j];
			j++;
		}	
		ret.push_back(s);
	}
	return ret;
}

void helpRemove(int parent) {
	for (auto& son : sons[parent]) {
		helpRemove(son.id);
		sons[parent].erase(son);
	}
}

int dfsRemove(vector<string> names, int level, int parent) {
	if (level == names.size() - 1) {
		for (auto& son : sons[parent]) {
			if (son.name == names[level]) {
				helpRemove(son.id);
				sons[parent].erase(son);				
			}
		}
	}
	for (auto& son : sons[parent]) {
		if (son.name == names[level]) {
//			if (son.type == 1)	return false;
//			return dfsCreate(names, level + 1, son.id, fileSize);
			dfsRemove(names, level + 1, son.id);
		}
	}
}

void remove(char* str) {
	auto names = parseStr(str);
	dfsRemove(names, 0, 0);
}

bool dfsCreate(vector<string>& names, int level, int now, LL fileSize) {
	if (level == names.size() - 1) {
//		auto son = a[now].sons.find()
	}
	if (a[now].sons.find(names[level]) != a[now].sons.end()) {
		int sonId = a[now].sons[names[level]];
		if (a[sonId].type == 1)	return false;
		return dfsCreate(names, level, sonId, fileSize);
	} else {
		a.push_back(Node(names[level], a.size(), 0, 0));
		return dfsCreate(names, level, a.size() - 1, fileSize);
	}
}

bool create(char* path, int size) {
	auto names = parseStr(path);
	return dfsCreate(names, 0, 0, size);
}

int main() {
	scanf("%d", &n);	
	for (int i = 0; i < n; i++) {
		LL size;
		scanf("%s", op);
		if (op[0] == 'C') {
			scanf("%s%lld", str, &size);
			if (create(str, size)) {
				puts("Y");
			} else {
				puts("N");
			} 
		} else if (op[1] == 'R') {
			scanf("%s", str);
		} else {
			continue;
		}
	}
} 
