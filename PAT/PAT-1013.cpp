#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1010;
int n, m, k;
vector<int> edge[MAXN];
bool vis[MAXN];

void DFS(int now) {
    vis[now] = true;
    for (auto& city : edge[now]) {
        if (!vis[city]) {
            DFS(city);
        }
    }
}

int main() {
    int x, y;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 0; i < k; i++) {
        int cnt = 0;
        scanf("%d", &x);
        memset(vis, 0, sizeof(vis));
        vis[x] = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                DFS(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}
