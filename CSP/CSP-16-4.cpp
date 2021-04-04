#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 10010;
int t, n;
queue<pair<int, int>> ops[MAXN];
bool vis[MAXN];

bool dfs(int op, int now, int from) {
	if (vis[now])	return false;
	vis[now] = true;
	while (!ops[now].empty()) {
		auto& p = ops[now].front(); 
		if (op == p.first && from == p.second) {
			vis[now] = false;
			ops[now].pop();
			return true;
		} if (dfs(p.first ^ 1, p.second, now)) {
			ops[now].pop();
		} else {
			return false;
		}
	}
	vis[now] = false;
	return op == -1;
}

int main() {
	scanf("%d%d", &t, &n);
	getchar();
	while (t--) {
//		while (!ops.empty())	ops.pop();
		for (int i = 0; i < n; i++) {
			vis[i] = false;
			ops[i] = queue<pair<int, int>>();
			string line;
			getline(cin, line);
			stringstream ss(line);
			string str;
			while (ss >> str) {
				if (str[0] == 'S')	ops[i].push(make_pair(0, stoi(str.substr(1))));
				else 	ops[i].push(make_pair(1, stoi(str.substr(1))));
			}
		}
		bool success = true;
		for (int i = 0; i < n; i++) {
			if (!dfs(-1, i, -1)) {
				success = false;
				break;
			}
		}
		if (success)	puts("0");
		else 			puts("1");
	}
	return 0;
}
