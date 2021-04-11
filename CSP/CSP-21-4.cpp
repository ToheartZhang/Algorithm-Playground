#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 110, MAXM = 11;
typedef pair<int, int> PII;
int n, m, k, cnt, sum;
int food[MAXN][MAXM], head[MAXN];
struct Edge {
	int to, val, nxt;
} edges[2*MAXN];

void add(int a, int b, int c) {
	edges[cnt].to = b;
	edges[cnt].val = c;
	edges[cnt].nxt = head[a];
	head[a] = cnt++;
}

PII dfs(int now, int fa, int f) {
	PII ret(0, -1);
	if (food[now][f]) {
		ret.second = 0;
	}
	for (int i = head[now]; ~i; i = edges[i].nxt) {
		int to = edges[i].to;
		if (to == fa)	continue;
		auto res = dfs(to, now, f);
		if (res.second != -1) {
			ret.first += res.first + edges[i].val*2;
			ret.second = max(ret.second, res.second + edges[i].val);
		}
	}
	return ret;
}

void init() {
	memset(head, -1, sizeof(head));
}

int main() {
	init();
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			scanf("%d", &food[i][j]);
		}
	}
	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		int nowAns = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++) {
			auto res = dfs(j, 0, i);
			if (res.second != -1) {
//				if (res.first - res.second == 9)	puts("11111");
				nowAns = min(nowAns, res.first - res.second);
			}
		}
		ans = max(nowAns, ans);
	}
	printf("%d\n", ans);
	return 0;
}
