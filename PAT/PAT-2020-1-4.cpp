#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 100010;
struct Node {
    int rnd, num;
    bool operator<(const Node& q) const {
        if (rnd != q.rnd)   return rnd < q.rnd;
        return num < q.num;
    }
    bool operator>(const Node& q) const {
        if (rnd != q.rnd)   return rnd > q.rnd;
        return num > q.num;
    }
} a[MAXN];
priority_queue<Node,vector<Node>,greater<Node>> q;
int n, m, maxRnd, cnt;
bool vis[MAXN];
vector<int> rndId[MAXN];

bool cmp(Node& p, Node &q) {
    if (p.rnd != q.rnd)
        return p.rnd < q.rnd;
    return p.num < q.num;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].num);
    }
    for (int i = 0; i < min(m, n); i++) {
        q.push(a[i]);
        vis[i] = true;
        cnt++;
    }
    int idx = m;
    Node lst;
    int rnd = 0;
    while (true) {
        int idx = 0;
        bool isFirst = true;
        for (; idx < n && q.size() <= m; idx++) {
            if (!vis[idx]) {
                if (q.empty() || a[idx].num >= q.top().num) {
                    if (q.size() == m) {
                        if (!isFirst) {
                            printf(" ");
                        }
                        isFirst = false;
                        printf("%d", q.top().num);
                        q.pop();
                    }
                    q.push(a[idx]);
                    vis[idx] = true;
                    a[idx].rnd = rnd;
                    cnt++;
                }
            }
        }
        while(!q.empty()) {
            if (!isFirst) {
                printf(" ");
            }
            isFirst = false;
            printf("%d", q.top().num);
            q.pop();
        }
        printf("\n");
        if (cnt == n)   break;
        rnd++;
    }
    return 0;
}