#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 0x3f3f3f3f;
int n, m, c1, c2;
int weight[MAXN], dis[MAXN], g[MAXN][MAXN], sum[MAXN], shorts[MAXN];
bool vis[MAXN];

int main() {
    int a, b, c;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    fill(g[0], g[0] + MAXN*MAXN, INF);
    fill(dis, dis + MAXN, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = c;
    }
    dis[c1] = 0;
    sum[c1] = weight[c1];
    shorts[c1] = 1;
    for (int i = 0; i < n; i++) {
        int to = -1, minDis = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && minDis > dis[j]) {
                to = j;
                minDis = dis[j];
            }
        }
        if (to == -1)   break;
        vis[to] = true;
        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                if(dis[to] + g[to][j] < dis[j]) {
                    dis[j] = dis[to] + g[to][j];
                    sum[j] = weight[j] + sum[to];
                    shorts[j] = shorts[to];
                } else if (dis[to] + g[to][j] == dis[j]) {
                    shorts[j] = shorts[j] + shorts[to];
                    if (sum[to] + weight[j] > sum[j]) {
                        sum[j] = sum[to] + weight[j];
                    }
                }
            } 
        }
    }
    printf("%d %d\n", shorts[c2], sum[c2]);
    return 0;
}
