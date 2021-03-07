#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100010;

struct Node {
    vector<int> childs;
    double data;
} a[MAXN];

int n;
double p, r;
double sum = 0;

void DFS(int root, double nowPrice) {
    if (a[root].childs.size() == 0) {
        sum += (a[root].data*nowPrice);
        return;
    }
    nowPrice *= r;
    for (int& child : a[root].childs) {
        DFS(child, nowPrice);
    }
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    r = r/100 + 1.0;
    for (int i = 0; i < n; i++) {
        int cnt;
        scanf("%d", &cnt);
        if (cnt > 0) {
            for (int j = 0; j < cnt; j++) {
                int node;
                scanf("%d", &node);
                a[i].childs.push_back(node);
            }
        } else {
            scanf("%lf", &a[i].data);
        }
    }
    DFS(0, p);
    printf("%.1lf\n", sum);

    return 0;
}
