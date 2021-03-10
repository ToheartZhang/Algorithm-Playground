#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 510, INF = 0x3f3f3f3f;
int cmax, n, s, m;
int c[MAXN], g[MAXN][MAXN], dis[MAXN], minSend = INF, minBack = INF;
bool vis[MAXN];
vector<int> pre[MAXN], path, ansPath;

void dijkstra(int src) {
    dis[src] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, minDis = INF;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && dis[j] < minDis) {
                minDis = dis[j];
                u = j;
            }
        }
        if (u == -1)    break;
        vis[u] = true;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && g[u][j] != INF) {
                if (dis[j] > dis[u] + g[u][j]) {
                    dis[j] = dis[u] + g[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                } else if (dis[j] == dis[u] + g[u][j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
}

void dfs(int from) {
    path.push_back(from);
    if (from == 0) {
        int send = 0, back = 0;
        for (int i = path.size() - 2; i >= 0; i--) {
            if (c[path[i]] > 0) {
                back += c[path[i]];
            } else if (c[path[i]] < 0) {
                int temp = back + c[path[i]];
                back = max(temp, 0);
                if (temp < 0) {
                    send -= temp;
                }
            }
        }
        if (send < minSend) {
            minSend = send;
            minBack = back;
            ansPath = path;
        } else if (send == minSend && back < minBack) {
            minBack = back;
            ansPath = path;
        }
        path.pop_back();
        return;
    }
    for (auto& to : pre[from]) {
        dfs(to);
    }
    path.pop_back();
}

int main() {
    fill(dis, dis + MAXN, INF);
    fill(g[0], g[0] + MAXN*MAXN, INF);
    scanf("%d%d%d%d", &cmax, &n, &s, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        c[i] -= cmax/2;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &g[b][a]);
        g[a][b] = g[b][a];
    }
    dijkstra(0);
    dfs(s);
    printf("%d 0", minSend);
    for (int i = ansPath.size() - 2; i >= 0; i--) {
        printf("->%d", ansPath[i]);
    }
    printf(" %d\n", minBack);
    return 0;
}
