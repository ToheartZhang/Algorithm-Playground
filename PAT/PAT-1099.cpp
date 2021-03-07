#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 110;
struct Node {
    int left, right, val;
} a[MAXN];
int n, in[MAXN], index;
queue<int> q;

void inOrder(int root) {
    if (a[root].left != -1) {
        inOrder(a[root].left);
    }
    a[root].val = in[index++];
    if (a[root].right != -1) {
        inOrder(a[root].right);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].left, &a[i].right);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    sort(in, in + n);
    inOrder(0);
    q.push(0);
    printf("%d", a[0].val);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (a[now].left != -1) {
            printf(" %d", a[a[now].left].val);
            q.push(a[now].left);
        }
        if (a[now].right != -1) {
            printf(" %d", a[a[now].right].val);
            q.push(a[now].right);
        }
    }
    printf("\n");
    return 0;
}