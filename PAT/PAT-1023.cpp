#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char s[22];
int cnt[11], newCnt[11];

struct Num {
    int digit[22];
    int len;
    Num() {
        memset(digit, 0, sizeof(digit));
        len = 0;
    }
} a;

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

Num mul(Num& lhs, int rhs = 2) {
    Num ret;
    int carry = 0;
    for (int i = 0; i < lhs.len; i++) {
        int now = lhs.digit[i]*rhs + carry;
        ret.digit[ret.len++] = now % 10;
        carry = now / 10;
    }
    while (carry) {
        ret.digit[ret.len++] = carry % 10;
        carry /= 10;
    }

    return ret;
}

void getCnt(int* nowCnt, Num& lhs) {
    for (int i = 0; i < lhs.len; i++) {
        nowCnt[lhs.digit[i]]++;
    }
}

bool isSame(int* cnta, int* cntb) {
    for (int i = 0; i < 9; i++) {
        if (cnta[i] != cntb[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%s", s);
    copy(s, a);
    getCnt(cnt, a);
    Num res = mul(a);
    getCnt(newCnt, res);
    if (isSame(cnt, newCnt)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    output(res);

    return 0;
}
