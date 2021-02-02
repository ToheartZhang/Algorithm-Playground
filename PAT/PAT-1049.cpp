#include <cstdio>
#include <iostream>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int ans = 0;
    int a = 1;
    while (n / a != 0) {
        int now = n / a % 10;
        int left = n / a / 10;
        int right = n % a;
        if (now == 0) {
            ans += left*a;
        } else if (now == 1) {
            ans += (left*a + right + 1);
        } else {
            ans += (left*a + a);
        }
        a *= 10;
    }
    printf("%d\n", ans);

    return 0;
}
