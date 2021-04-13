#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 22;
struct Node {
    int left, right, val;
} a[MAXN];
int in[MAXN], pre[MAXN], n;
int maxLevel = -1;
queue<int> q;

void dfs(int root, int midL, int midR, int level) {
    if (midR - midL < 1) {
        return;
    }
    int midIdx = 0;
    for (int i = midL; i < midR; i++) {
        if (pre[root] == in[i]) {
            midIdx = i;
            break;
        }
    }
    if (maxLevel < level) {
        if (level != 0) {
            printf(" ");
        }
        printf("%d", pre[root]);
        maxLevel = level;
    }
    dfs(root + 1, midL, midIdx, level + 1);
    dfs(root + (midIdx - midL) + 1, midIdx + 1, midR, level + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    dfs(0, 0, n, 0);
    printf("\n");
    return 0;
}
