#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int c[MAXN], p[MAXN];
int nc, np;

bool cmp(int &a, int &b) {
    return a > b;
}

int main() {
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &p[i]);
    }
    sort(c, c + nc, cmp);
    sort(p, p + np, cmp);
    int ans = 0;
    for (int i = 0; i < nc && i < np; i++) {
        if (c[i] >= 0 && p[i] >= 0) {
            ans += c[i]*p[i];
        } else {
            break;
        }
    }
    for (int i = 0; i < nc && i < np; i++) {
        if (c[nc - i - 1] <= 0 && p[np - i - 1] <= 0) {
            ans += c[nc - i - 1]*p[np - i - 1];
        } else {
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
}
