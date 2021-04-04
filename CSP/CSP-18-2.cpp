#include <cstdio>
#include <iostream>
using namespace std;

typedef pair<int, int> PII;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int ddx[] = {1, -1, 1, -1};
const int ddy[] = {1, -1, -1, 1};
const int MAXN = 1010;
int n;
PII a[MAXN];
int ans[5];

bool check(PII& p) {
	for (int i = 0; i < 4; i++) {
		bool find = false;
		for (int j = 0; j < n; j++) {
			if (p.first + dx[i] == a[j].first && p.second + dy[i] == a[j].second) {
				find = true;
				break;
			}
		}
		if (!find)	return false;
	}
	return true;
}

int getScore(PII& p) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			if (p.first + ddx[i] == a[j].first && p.second + ddy[i] == a[j].second) {
				ret++;
				break;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	} 
	for (int i = 0; i < n; i++) {
		if (check(a[i])) {
			ans[getScore(a[i])]++;
		}
	}
	for (int i = 0; i <= 4; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
