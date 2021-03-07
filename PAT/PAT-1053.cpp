#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 110;

struct Node {
    int w;
    vector<int> childs;
} a[MAXN];
int n, m, s, path[MAXN];

bool cmp(int p, int q) {
    return a[p].w > a[q].w;
}

void DFS(int index, int pathIdx) {
    if (path[pathIdx] > s) {
        return;
    } else if (path[pathIdx] == s && a[index].childs.size() == 0) {
        printf("%d", path[0]);
        for (int j = 1; j <= pathIdx; j++) {
            printf(" %d", path[j] - path[j - 1]);
        }
        printf("\n");
        return;
    }
    for (auto& item : a[index].childs) {
        path[pathIdx + 1] = path[pathIdx] + a[item].w;
        DFS(item, ++pathIdx);
        pathIdx--;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].w);
    }
    for (int i = 0; i < m; i++) {
        int id, num, child;
        scanf("%d%d", &id, &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &child);
            a[id].childs.push_back(child);
        }
        sort(a[id].childs.begin(), a[id].childs.end(), cmp);
    }
    path[0] = a[0].w;
    DFS(0, 0);
}
