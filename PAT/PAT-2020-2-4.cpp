#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1010, INF = 0x3f3f3f3f;
struct Edge {
    int to, s, d;
};
int n, m, cnt, k;
int ind[MAXN], backInd[MAXN], dis[MAXN], vouch[MAXN];
bool vis[MAXN];
vector<Edge> edges[MAXN];
int pre[MAXN];
queue<int> q;

void topSort() {
    for (int i = 0; i < n; i++) {
        backInd[i] = ind[i];
        if (!ind[i]) {
            q.push(i);
            edges[n].push_back({i, 0, 0});
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        for (auto& edge : edges[now]) {
            ind[edge.to]--;
            if (!ind[edge.to]) {
                q.push(edge.to);
            }
        }
    }
}

void dijkstra(int src) {
    fill(dis, dis + MAXN, INF);
    dis[src] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, minDis = INF;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && dis[j] < minDis) {
                u = j;
                minDis = dis[j];
            }
        }
        if (u == -1)    break;
        vis[u] = true;
        for (auto& edge : edges[u]) {
            if (!vis[edge.to]) {
                if (dis[edge.to] > dis[u] + edge.s) {
                    dis[edge.to] = dis[u] + edge.s;
                    vouch[edge.to] = vouch[u] + edge.d;
                    pre[edge.to] = u;
                } else if (dis[edge.to] == dis[u] + edge.s && vouch[edge.to] < vouch[u] + edge.d) {
                    vouch[edge.to] = vouch[u] + edge.d;
                    pre[edge.to] = u;
                }
            }
        }
    }
}

void dfs(int now) {
    if (now == n) {
        return;
    }
    dfs(pre[now]);
    if (pre[now] != n) {
        printf("->");
    }
    printf("%d", now);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int from, to, s, d;
        scanf("%d%d%d%d", &from, &to, &s, &d);
        edges[from].push_back({to, s, d});
        ind[to]++;
    }
    topSort();
    if (cnt < n) {
        printf("Impossible.\n");
    } else {
        printf("Okay.\n");        
    }
    dijkstra(n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int now;
        scanf("%d", &now);
        if (backInd[now] == 0) {
            printf("You may take test %d directly.\n", now);
            continue;
        } else if (cnt < n) {
            printf("Error.\n");
            continue;
        }
        dfs(now);
        printf("\n");
    }
    return 0;
}