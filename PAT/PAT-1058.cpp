#include <cstdio>
#include <iostream>
using namespace std;

const int BASE[] = {0, 17, 29};

int main() {
    int a[3];
    int b[3];
    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
    scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
    for (int i = 2; i >= 1; i--) {
        a[i] += b[i];
        a[i - 1] += a[i] / BASE[i];
        a[i] %= BASE[i];
    }
    a[0] += b[0];
    printf("%d.%d.%d\n", a[0], a[1], a[2]);

    return 0;
}
