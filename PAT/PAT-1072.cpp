#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;;

const int MAXN = 2020, INF = 0x3f3f3f3f;
struct Edge {
    int to, w;
};
int n, m, k, d, gasMinDis = 0, finalGas = -1, nowMinDis = 0;
double nowAvgDis = 0, gasAvgDis = -1;
int dis[MAXN];
bool vis[MAXN];
vector<Edge> edges[MAXN];

int getNum(char* s) {
    if (s[0] == 'G') {
        return atoi(s + 1) + n;
    }
    return atoi(s);
}

void dijkstra(int src) {
    dis[src] = 0;
    for (int i = 1; i <= n + m; i++) {
        int u = -1, minDis = INF;
        for (int j = 1; j <= n + m; j++) {
            if (!vis[j] && dis[j] < minDis) {
                minDis = dis[j];
                u = j;
            }
        }
        if (u == -1)    break;
        vis[u] = true;
        for (auto& edge : edges[u]) {
            if (!vis[edge.to] && dis[edge.to] > dis[u] + edge.w) {
                dis[edge.to] = dis[u] + edge.w;
            }
        }
    }
}

void handleGas(int gas) {
    fill(dis, dis + MAXN, INF);
    memset(vis, 0, sizeof(vis));
    nowMinDis = INF;
    nowAvgDis = 0.0;
    dijkstra(gas);
    for (int i = 1; i <= n; i++) {
        if (dis[i] > d) {
            nowMinDis = INF;
            return;
        }
        nowMinDis = min(nowMinDis, dis[i]);
        nowAvgDis += dis[i];
    }
    nowAvgDis /= n;
}

int main() {
    char a[10], b[10];
    scanf("%d%d%d%d", &n, &m, &k, &d);
    for (int i = 0; i < k; i++) {
        int x, y, w;
        scanf("%s%s%d", a, b, &w);
        x = getNum(a);
        y = getNum(b);
        edges[x].push_back({y, w});
        edges[y].push_back({x, w});
    }
    for (int i = n + 1; i <= n + m; i++) {
        handleGas(i);
        if (nowMinDis == INF)   continue;
        if (gasMinDis < nowMinDis) {
            gasMinDis = nowMinDis;
            gasAvgDis = nowAvgDis;
            finalGas = i;
        } else if (gasMinDis == nowMinDis && gasAvgDis > nowAvgDis) {
            gasAvgDis = nowAvgDis;
            finalGas = i;
        }
    }
    if (finalGas == -1) {
        printf("No Solution\n");
    } else {
        printf("G%d\n%.1lf %.1lf\n", finalGas - n, (double)gasMinDis, gasAvgDis);
    }
    return 0;
}