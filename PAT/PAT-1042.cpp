/*
 * Description: Change value according to given order for k times.
 * Solution: Just stimulate it. Be careful to mod num.
 */

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 60;

int n;
int a[MAXN];
int cards1[MAXN], cards2[MAXN];

const char CAP_ORDER[] = {'S', 'H', 'C', 'D', 'J'};

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 54; i++) {
        scanf("%d", &a[i]);
        cards1[i] = i;
    }

    // cards[a[nowPos]] = nowVal;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= 54; i++) {
            cards2[a[i]] = cards1[i];
        }
        for (int i = 1; i <= 54; i++) {
            cards1[i] = cards2[i];
        }
    }

    for (int i = 1; i <= 54; i++) {
        int now = cards1[i];
        int idx = (now - 1) / 13;
        printf("%c%d", CAP_ORDER[idx], (now - 1) % 13 + 1);
        if (i < 54) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
