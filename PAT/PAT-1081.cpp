#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 110;

struct Fraction {
    int up;
    int down = 1;
} a[MAXN], result;

int n;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

void simplify(Fraction& lhs) {
    if (lhs.up == 0) {
        lhs.down = 1;
        return;
    }
    int factor = gcd(abs(lhs.up), abs(lhs.down));
    lhs.up /= factor;
    lhs.down /= factor;
    if (lhs.down < 0) {
        lhs.down = -lhs.down;
        lhs.up = -lhs.up;
    }
}

void add(Fraction& lhs, Fraction& rhs) {
    Fraction temp;
    temp.up = lhs.up*rhs.down + rhs.up*lhs.down;
    temp.down = lhs.down*rhs.down;
    lhs = temp;
    simplify(lhs);
}

void output(Fraction& lhs) {
    if (lhs.down == 1) {
        printf("%d\n", lhs.up);
    } else if (abs(lhs.up) < abs(lhs.down)) {
        printf("%d/%d\n", lhs.up, lhs.down);
    } else {
        int integer = lhs.up / lhs.down;
        printf("%d %d/%d\n", integer, abs(lhs.up) % lhs.down, lhs.down);
    }
}

int main() {
    // result.down = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d/%d", &a[i].up, &a[i].down);
        add(result, a[i]);
    }
    output(result);

    return 0;
}
