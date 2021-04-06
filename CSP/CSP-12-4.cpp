#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1e6;
const int MAXN = 550;
const int MAXM = 2*100010;
int n, m, cnt;
int head[MAXN], dis[MAXN][1010];
bool vis[MAXN][1010];
struct Edge {
	int to, val, nxt, type;
} edges[MAXM];
struct Node {
	int id, tot, dis;
	bool operator<(const Node& rhs) const {
		return dis > rhs.dis;
	}
};
priority_queue<Node> q;

void add(int t, int a, int b, int c) {
	edges[cnt].type = t;
	edges[cnt].to = b;
	edges[cnt].val = c;
	edges[cnt].nxt = head[a];
	head[a] = cnt++;
}

void dijkstra() {
	q.push({1, 0, 0});
	dis[1][0] = 0;
	while (!q.empty()) {
		auto now = q.top();
		q.pop();
		if (vis[now.id][now.tot])	continue;
		vis[now.id][now.tot] = true;
		for (int i = head[now.id]; ~i; i = edges[i].nxt) {
//			cout << "111" << endl; 
			int to = edges[i].to, newVal = now.tot;
			if (edges[i].type == 0) {
//				if (vis[to][0])	continue;
				if (dis[to][0] > now.dis + edges[i].val) {
					dis[to][0] = now.dis + edges[i].val;
					if (dis[to][0] <= INF)
						q.push({to, 0, dis[to][0]});
				}
			} else {
				newVal += edges[i].val;
//				if (vis[to][now.tot + 1])	continue;
				if (newVal > 1000)	continue;
				if (dis[to][newVal] > now.dis - now.tot*now.tot + newVal*newVal) {
					dis[to][newVal] = now.dis - now.tot*now.tot + newVal*newVal;
					if (dis[to][newVal] <= INF)
						q.push({to, newVal, dis[to][newVal]});
				}
			}
		}
	}
}

void init() {
	memset(head, -1, sizeof(head));
	memset(dis, 0x3f, sizeof(dis));
}

int main() {
	init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int t, a, b, c;
		scanf("%d%d%d%d", &t, &a, &b, &c);
		add(t, a, b, c);
		add(t, b, a, c);
	}
	dijkstra();
	int ans = INF;
	for (int i = 0; i <= 1000; i++) {
		ans = min(ans, dis[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
