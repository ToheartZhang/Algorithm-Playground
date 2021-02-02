#include <cstdio>
#include <iostream>
using namespace std;

struct Fraction {
    long long up;
    long long down = 1;
} a, b;

long long gcd(long long x, long long y) {
    return y ? gcd(y, x % y) : x;
}

void simplify(Fraction& lhs) {
    if (lhs.up == 0) {
        lhs.down = 1;
        return;
    }
    long long factor = gcd(abs(lhs.up), abs(lhs.down));
    lhs.up /= factor;
    lhs.down /= factor;
    if (lhs.down < 0) {
        lhs.down = -lhs.down;
        lhs.up = -lhs.up;
    }
}

void output(Fraction lhs) {
    bool flag = lhs.up < 0;
    if (flag) {
        printf("(");
    }
    if (lhs.down == 1) {
        printf("%lld", lhs.up);
    } else if (lhs.down == 0) {
        printf("Inf");
    } else if (abs(lhs.up) < abs(lhs.down)) {
        printf("%lld/%lld", lhs.up, lhs.down);
    } else {
        long long integer = lhs.up / lhs.down;
        printf("%lld %lld/%lld", integer, abs(lhs.up) % lhs.down, lhs.down);
    }
    if (flag) {
        printf(")");
    }
}

Fraction add(Fraction& lhs, Fraction& rhs) {
    Fraction temp;
    temp.up = lhs.up*rhs.down + rhs.up*lhs.down;
    temp.down = lhs.down*rhs.down;
    simplify(temp);
    return temp;
}

Fraction sub(Fraction& lhs, Fraction& rhs) {
    Fraction temp;
    temp.up = lhs.up*rhs.down - rhs.up*lhs.down;
    temp.down = lhs.down*rhs.down;
    simplify(temp);
    return temp;
}

Fraction mul(Fraction& lhs, Fraction& rhs) {
    Fraction temp;
    temp.up = lhs.up*rhs.up;
    temp.down = lhs.down*rhs.down;
    simplify(temp);
    return temp;
}

Fraction div(Fraction& lhs, Fraction& rhs) {
    Fraction temp;
    temp.up = lhs.up*rhs.down;
    temp.down = lhs.down*rhs.up;
    simplify(temp);
    return temp;
}

Fraction (*opt[4])(Fraction&, Fraction&) = {add, sub, mul, div};
const char OPT_CHAR[] = {'+', '-', '*', '/'};

void outputExp(Fraction& lhs, Fraction& rhs, int idx) {
    output(lhs);
    printf(" %c ", OPT_CHAR[idx]);
    output(rhs);
    printf(" = ");
    output(opt[idx](a, b));
    printf("\n");
}

int main() {
    scanf("%lld/%lld", &a.up, &a.down);
    scanf("%lld/%lld", &b.up, &b.down);
    simplify(a);
    simplify(b);
    for (int i = 0; i < 4; i++) {
        outputExp(a, b, i);
    }

    return 0;
}
