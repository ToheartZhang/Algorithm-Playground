#include <cstdio>
#include <iostream>

using namespace std;

const char CHOOSE[] = {'W', 'T', 'L'};

int main() {
    double ans = 1;
    for (int i = 0; i < 3; i++) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        int pos = 0;
        double nowMax = a;
        if (b > nowMax) {
            pos = 1;
            nowMax = b;
        }
        if (c > nowMax) {
            pos = 2;
            nowMax = c;
        }
        printf("%c ", CHOOSE[pos]);
        ans *= max(max(a, b), c);
    }
    ans = (ans * 0.65 - 1) * 2;
    printf("%.2lf\n", ans);

    return 0;
}
