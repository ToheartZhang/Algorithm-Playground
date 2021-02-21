#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int left, right;
};

const int MAXN = 12;

int n, allRoot;
Node nodes[MAXN];
bool vis[MAXN], isFirst = true;

void invert(int root) {
    if (nodes[root].left != -1) {
        invert(nodes[root].left);
    }
    if (nodes[root].right != -1) {
        invert(nodes[root].right);
    }
    swap(nodes[root].left, nodes[root].right);
}

void BFS() {
    queue<int> q;
    q.push(allRoot);
    printf("%d", allRoot);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (nodes[now].left != -1) {
            printf(" %d", nodes[now].left);
            q.push(nodes[now].left);
        }
        if (nodes[now].right != -1) {
            printf(" %d", nodes[now].right);
            q.push(nodes[now].right);
        }
    }
}

void inOrder(int root) {
    if (nodes[root].left != -1) {
        inOrder(nodes[root].left);
    }
    if (isFirst) {
        isFirst = false;
    } else {
        printf(" ");
    }
    printf("%d", root);
    if (nodes[root].right != -1) {
        inOrder(nodes[root].right);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char l, r;
        scanf("%*c%c %c", &l, &r);
        if (l == '-') {
            nodes[i].left = -1;
        } else {
            nodes[i].left = l - '0';
            vis[l - '0'] = true;
        }
        if (r == '-') {
            nodes[i].right = -1;
        } else {
            nodes[i].right = r - '0';
            vis[r - '0'] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            allRoot = i;
            break;
        }
    }
    invert(allRoot);
    BFS();
    printf("\n");
    inOrder(allRoot);
    printf("\n");

    return 0;
}
