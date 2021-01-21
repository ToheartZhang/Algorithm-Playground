/*
 * Description: Given a, b, c in longlong, return if a + b > c
 * Solution: Make use of computer theory about overflow.
 */

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int main() {
    LL a, b, c;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Case #%d: ", i);
        scanf("%lld%lld%lld", &a, &b, &c);
        LL res = a + b;
        if (a > 0 && b > 0 && res < 0) {
            printf("true\n");
        } else if (a < 0 && b < 0 && res >= 0) {
            printf("false\n");
        } else if (res > c) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }

    return 0;
}