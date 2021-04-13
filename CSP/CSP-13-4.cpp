#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int t;
int a[4][4];

void init() {
	memset(a, 0, sizeof(a));
}

bool isSucc(int now) {
	for (int i = 0; i < 3; i++) {
		bool succ = true;
		for (int j = 0; j < 3; j++) {
			if (now != a[i][j]) {
				succ = false;
				break;
			}
		}
		if (succ)	return true;
		succ = true;
		for (int j = 0; j < 3; j++) {
			if (now != a[j][i]) {
				succ = false;
				break;
			}
		}
		if (succ)	return true;
	}
	bool succ = true;
	for (int i = 0; i < 3; i++) {
		if (now != a[i][i]) {
			succ = false;
			break;
		}
	}
	if (succ)	return true;
	succ = true;
	for (int i = 0; i < 3; i++) {
		if (now != a[i][3 - i - 1]) {
			return false;
		}
	}
	return true;
}

int check() {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!a[i][j])	cnt++;
		} 
	}
	if (isSucc(1))	return cnt + 1;
	if (isSucc(2))	return -cnt - 1;
	if (!cnt)	return 0;
	return INF; 
}

int dfs(int now) {
	auto res = check();
	if (res != INF) {
		return res;
	}
	if (!now) {
		res = -INF;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!a[i][j]) {
					a[i][j] = 1;
					res = max(res, dfs(1));
					a[i][j] = 0;
				}
			}
		}
	} else {
		res = INF;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!a[i][j]) {
					a[i][j] = 2;
					res = min(res, dfs(0));
					a[i][j] = 0;
				}
			}
		}
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		init();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		printf("%d\n", dfs(0));
	}
}
