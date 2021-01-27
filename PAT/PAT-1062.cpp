#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct Node {
    int id;
    int virtue;
    int talent;
    int flag;
} a[MAXN];

int n, l, h;

bool cmp(Node& x, Node& y) {
    if (x.flag != y.flag) {
        return x.flag < y.flag;
    }
    int xSum = x.virtue + x.talent;
    int ySum = y.virtue + y.talent;
    if (xSum != ySum) {
        return xSum > ySum;
    } else if (x.virtue != y.virtue) {
        return x.virtue > y.virtue;
    }
    return x.id < y.id;
}

int main() {
    scanf("%d%d%d", &n, &l, &h);
    int m = n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i].id, &a[i].virtue, &a[i].talent);
        if (a[i].virtue < l || a[i].talent < l) {
            a[i].flag = 5;
            m--;
        } else if (a[i].virtue < h && a[i].talent < h && a[i].virtue >= a[i].talent) {
            a[i].flag = 3;
        } else if (a[i].virtue >= h && a[i].talent < h) {
            a[i].flag = 2;
        } else if (a[i].virtue >= h && a[i].talent >= h) {
            a[i].flag = 1;
        } else {
            a[i].flag = 4;
        }
    }
    sort(a, a + n, cmp);
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d %d %d\n", a[i].id, a[i].virtue, a[i].talent);
    }

    return 0;
}
