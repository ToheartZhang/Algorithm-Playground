#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
vector<int> edge[MAXN];
set<int> roots;
set<int> result;
bool vis[MAXN];
int n, cnt, maxLevel;

void DFS(int node) {
    vis[node] = true;
    for (auto& n : edge[node]) {
        if (!vis[n])
            DFS(n);
    }
}

void deepin(int node, int level) {
    if (level > maxLevel) {
        roots.clear();
        maxLevel = level;
        roots.insert(node);
    } else if (level == maxLevel) {
        roots.insert(node);
    }
    vis[node] = true;
    for (auto& n : edge[node]) {
        if (!vis[n])
            deepin(n, level + 1);
    }    
} 

int main() {
    int x, y;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            DFS(i);
            cnt++;
        }
    }
    if (cnt > 1) {
        printf("Error: %d components\n", cnt);
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    deepin(1, 1);
    set_union(roots.begin(), roots.end(), result.begin(), result.end(), inserter(result, result.end()));
    memset(vis, 0, sizeof(vis));
    maxLevel = 0;
    auto deepRoot = *(roots.begin());
    roots.clear();
    deepin(deepRoot, 1);
    set_union(roots.begin(), roots.end(), result.begin(), result.end(), inserter(result, result.end()));
    for (auto& root : result) {
        printf("%d\n", root);
    }
    return 0;
}
