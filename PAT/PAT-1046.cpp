/*
 * Discription: Given a circle, calculate shortest path between points.
 * Solution: Think of complementary.
 */

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100010;

int n, m;
int a[MAXN];
int coord1[MAXN];

int main() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (i > 1)
            coord1[i] = coord1[i - 1] + a[i - 1];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y < x)
            swap(x, y);
        int delta1 = abs(coord1[x] - coord1[y]);
        int delta2 = sum - delta1;
        printf("%d\n", min(delta1, delta2));
    }

    return 0;
}
