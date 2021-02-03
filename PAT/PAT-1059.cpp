#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct Factor {
    int val;
    int cnt;
} fac[11];

const int MAXN = 2010;

int prime[MAXN], pNum = 0;
bool notPrime[MAXN];
int n;

void findPrime() {
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i < MAXN; i++) {
        if (notPrime[i] == false) {
            prime[pNum++] = i;
        }
        for (int j = i*i; j <= MAXN; j += i) {
            notPrime[j] = true;
        }
    }
}

int main() {
    findPrime();
    scanf("%d", &n);
    printf("%d=", n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    int sqrn = sqrt(n);
    bool isBegin = true;
    for (int i = 0; i < pNum && i <= sqrn; i++) {
        int prod = prime[i];
        int cnt = 1;
        if (n % prime[i] == 0) {
            if (!isBegin) {
                printf("*");
            }
            isBegin = false;
            printf("%d", prime[i]);
            prod *= prime[i];
            while (n % prod == 0) {
                cnt++;
                prod *= prime[i];
            }
            if (cnt > 1) {
                printf("^%d", cnt);
            }
        }
    }
    printf("\n");

    return 0;
}
