#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long LL;

LL n;
LL maxLen, maxBegin, maxEnd;

int main() {
    scanf("%lld", &n);
    LL sqrn = sqrt(n);
    for (int i = 2; i <= sqrn; i++) {
        if (n % i == 0) {
            LL cnt = i;
            LL prod = i;
            while (n % prod == 0) {
                if (cnt - i + 1 > maxLen) {
                    maxBegin = i;
                    maxEnd = cnt;
                    maxLen = cnt - i + 1;
                }
                cnt++;
                prod *= cnt;
            }
        }
    }
    if (maxLen == 0) {
        maxLen = 1;
        maxBegin = n;
        maxEnd = n;
    }
    printf("%lld\n", maxLen);
    for (int i = maxBegin; i <= maxEnd; i++) {
        if (i != maxBegin) {
            printf("*");
        }
        printf("%d", i);
    }
    printf("\n");

    return 0;
}
