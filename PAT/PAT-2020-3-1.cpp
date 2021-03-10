#include <cstdio>
#include <iostream>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int p = 0, q = 1, temp;
    while (q <= n) {
        temp = p + q;
        p = q;
        q = temp;
    }
    if (abs(p - n) <= abs(q - n)) {
        printf("%d\n", p);
    } else {
        printf("%d\n", q);
    }
    return 0;
}