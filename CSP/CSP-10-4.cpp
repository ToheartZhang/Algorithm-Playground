#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int MAXM = 200010;
int n, m;
struct Edge {
	int from, to, val;
} a[MAXM];
int fa[MAXN];

bool cmp(Edge& p, Edge& q) {
	return p.val < q.val;
}

int getFather(int x) {
	if (x == fa[x])	return x;
	return fa[x] = getFather(fa[x]);
}

void kruskal() {
	for (int i = 0; i <= n; i++) {
		fa[i] = i;
	}
	sort(a, a + m, cmp);
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int faX = getFather(a[i].from), faY = getFather(a[i].to);
		if (faX != faY) {
			fa[faX] = faY;
			cnt++;
			if (getFather(1) == getFather(n)) {
				printf("%d\n", a[i].val);
				return;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		a[i].from = x;
		a[i].to = y;
		a[i].val = c;
	}
	kruskal();
	return 0;
} 
