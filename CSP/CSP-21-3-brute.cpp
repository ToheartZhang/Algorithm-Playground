#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 1000010;
char str[110];
int n, cnt;
struct Node {
	int type;
	map<string, int> sons;
} a[MAXN];

vector<string> getPath(char* str) {
	vector<string> ret;
	int len = strlen(str);
	for (int i = 1; i < len; i++) {
		string s;
		int j = i;
		while (j < len && str[j] != '/')	s += str[j++];
		ret.push_back(s);
		i = j;
	}
	return ret;
}

bool dfsCreate(vector<string> path, int level, int now) {
	auto name = path[level];
	if (level == path.size() - 1) {
		auto it = a[now].sons.find(name);
		if (it == a[now].sons.end()) {
			a[cnt++].type = 1;
			a[now].sons[name] = cnt - 1;
			return true;
		} else {
			if (a[a[now].sons[name]].type == 0) {
				return false;
			} else {
				return true;
			}
		}
	}
	auto it = a[now].sons.find(name);
	if (it == a[now].sons.end()) {
		a[cnt++].type = 0;
		a[now].sons[name] = cnt - 1;
		if (dfsCreate(path, level + 1, a[now].sons[name])) {
			return true;
		} else {
			a[now].sons.erase(it);
			return false;
		}	
	} else if (a[a[now].sons[name]].type == 1) {
		return false;
	} else {
		return dfsCreate(path, level + 1, a[now].sons[name]);
	} 
}

void create(char* str, int fileSize) {
	auto path = getPath(str);
	if (dfsCreate(path, 0, 0)) {
		puts("Y");
	} else {
		puts("N");
	}
} 

bool dfsRemove(vector<string> path, int level, int now) {
	auto name = path[level];
	if (level == path.size() - 1) {
		auto it = a[now].sons.find(name);
		if (it == a[now].sons.end()) {
			return false;
		} else {
			a[now].sons.erase(it);
			return true;
		}
	}
	auto it = a[now].sons.find(name);
	if (it == a[now].sons.end()) {
		return false;
	} else {
		return dfsRemove(path, level + 1, it->second);
	}
}

void remov(char* str) {
	auto path = getPath(str);
	dfsRemove(path, 0, 0);
	puts("Y");
}

int main() {
	scanf("%d", &n);
	cnt++;
	for (int i = 0; i < n; i++) {
		char temp[2];
		scanf("%s", temp);
		if (temp[0] == 'C') {
			int fileSize;
			scanf("%s%d", str, &fileSize);
			create(str, fileSize);
		} else if (temp[0] == 'R') {
			scanf("%s", str);
			remov(str);
		} else {
			int t1, t2;
			scanf("%s%d%d", str, &t1, &t2);
			puts("-");
		}
	}
	return 0;
}
