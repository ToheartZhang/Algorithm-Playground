#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
int n, k;
int hobby[MAXN], father[MAXN], unionCnt[MAXN], cnt;

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void unionSet(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) {
        father[fa] = fb;
    }
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d: ", &k);
        for (int j = 0; j < k; j++) {
            int h;
            scanf("%d", &h);
            if (hobby[h] == 0) {
                hobby[h] = i;
            } else {
                unionSet(i, hobby[h]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        unionCnt[findFather(i)]++;
    }
    for (int i = 1; i <= n; i++) {
        if (unionCnt[i] != 0) {
            cnt++;
        }
    }
    sort(unionCnt, unionCnt + n + 1, cmp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", unionCnt[i]);
    }
    printf("\n");
    return 0;
}
