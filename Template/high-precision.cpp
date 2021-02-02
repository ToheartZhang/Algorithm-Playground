#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1010;

struct Num {
    int digit[MAXN];
    int len;
    Num() {
        memset(digit, 0, sizeof(digit));
        len = 0;
    }
} a, b;

char s[MAXN];

void copy(char* s, Num& num) {
    int len = strlen(s);
    num.len = len;
    for (int i = 0; i < len; i++) {
        num.digit[len - i - 1] = s[i] - '0';
    }
}

void output(Num num) {
    for (int i = num.len - 1; i >= 0; i--) {
        printf("%d", num.digit[i]);
    }
    printf("\n");
}

int compare(Num& lhs, Num& rhs) {
    if (lhs.len < rhs.len) {
        return -1;
    } else if (lhs.len > rhs.len) {
        return 1;
    }
    for (int i = lhs.len - 1; i >= 0; i--) {
        if (lhs.digit[i] < rhs.digit[i]) {
            return -1;
        } else if (lhs.digit[i] > rhs.digit[i]) {
            return 1;
        }
    }
    return 0;
}

Num add(Num& lhs, Num& rhs) {
    Num ret;
    int carry = 0;
    for (int i = 0; i < lhs.len || i < rhs.len; i++) {
        int now = lhs.digit[i] + rhs.digit[i] + carry;
        ret.digit[ret.len++] = now % 10;
        carry = now / 10;
    }
    if (carry != 0) {
        ret.digit[ret.len++] = carry;
    }
    return ret;
}

Num sub(Num& lhs, Num& rhs) {
    Num ret;
    for (int i = 0; i < lhs.len || i < rhs.len; i++) {
        if (lhs.digit[i] < rhs.digit[i]) {
            ret.digit[ret.len + 1]--;
            ret.digit[ret.len] += 10;
        }
        ret.digit[ret.len++] += lhs.digit[i] - rhs.digit[i];
    }
    while (ret.len >= 2 && ret.digit[ret.len - 1] == 0) {
        ret.len--;
    }
    return ret;
}

Num mul(Num& lhs, int rhs) {
    Num ret;
    int carry = 0;
    for (int i = 0; i < lhs.len; i++) {
        int now = lhs.digit[i]*rhs + carry;
        ret.digit[ret.len++] = now % 10;
        carry = now / 10;
    }
    while (carry != 0) {
        ret.digit[ret.len++] = carry % 10;
        carry /= 10;
    }
    return ret;
}

Num div(Num& lhs, int rhs, int &r) {
    Num ret;
    ret.len = lhs.len;
    for (int i = lhs.len - 1; i >= 0; i--) {
        r = r*10 + lhs.digit[i];
        if (r < rhs) {
            ret.digit[i] = 0;
        } else {
            ret.digit[i] = r / rhs;
            r %= rhs;
        }
    }
    while (ret.len >= 2 && ret.digit[ret.len - 1] == 0) {
        ret.len--;
    }
    return ret;
}

int main() {
    // + -
    scanf("%s", s);
    copy(s, a);
    scanf("%s", s);
    copy(s, b);
    output(add(a, b));
    if (compare(a, b) < 0) {
        printf("-");
        output(sub(b, a));
    } else {
        output(sub(a, b));
    }

    // * /
    int d;
    scanf("%s", s);
    copy(s, a);
    scanf("%d", &d);
    output(mul(a, d));
    int r = 0;
    output(div(a, d, r));
    printf("%d\n", r);

    return 0;
}
