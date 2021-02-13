#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1010;

int np, ng;
int w[MAXN];

struct Pro {
    int id;
    int order;
    int weight;
    int rank;
} a[MAXN];

bool cmp(Pro& x, Pro& y) {
    return x.order < y.order;
}

bool cmp1(Pro& x, Pro& y) {
    return x.id < y.id;
}


queue<Pro> q;

int main() {
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < np; i++) {
        int order;
        scanf("%d", &order);
        a[i].order = i;
        a[i].id = order;
        a[i].weight = w[order];
    }
    for (int i = 0; i < np; i++) {
        q.push(a[i]);
    }
    while (!q.empty()) {
        int size = q.size();
        if (size == 1) {
            Pro temp = q.front();
            a[temp.order].rank = 1;
            break;
        }
        int groups = size / ng;
        int moder = size % ng;
        if (moder > 0) {
            groups++;
        }
        for (int i = 0; i < groups; i++) {
            int base = i*ng;
            int maxVal = 0;
            int maxIdx = -1;
            for (int j = 0; j < ng && base + j < size; j++) {
                Pro temp = q.front();
                q.pop();
                a[temp.order].rank = groups + 1;
                if (temp.weight > maxVal) {
                    maxVal = temp.weight;
                    maxIdx = temp.order;
                }
            }
            q.push(a[maxIdx]);
        }
    }
    sort(a, a + np, cmp1);
    for (int i = 0; i < np; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", a[i].rank);
    }
    printf("\n");

    return 0;
}
