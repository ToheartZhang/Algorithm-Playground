#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1010;

int digits;
char a[MAXN], b[MAXN];
char ba[MAXN], bb[MAXN];

int getPoint(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            return i;
        }
    }
    return len;
}

int getNo0(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != '.' && str[i] != '0') {
            return i;
        }
    }
    return len;
}

void getBase(char* dest, char* str, int no0Pos) {
    int len = strlen(str);
    int i = no0Pos;
    int cnt = 0;
    while (i < len && cnt < digits) {
        if (str[i] == '.') {
            i++;
            continue;
        }
        dest[cnt++] = str[i++];
    }
    if (cnt < digits) {
        for (i = cnt; i < digits; i++) {
            dest[i] = '0';
        }
    }
}

int main() {
    scanf("%d", &digits);
    scanf("%s%s", a, b);
    int lena = strlen(a);
    int lenb = strlen(b);
    int pointPosA = getPoint(a), pointPosB = getPoint(b);
    int no0PosA = getNo0(a), no0PosB = getNo0(b);
    int expA = pointPosA >= no0PosA ? pointPosA - no0PosA : pointPosA - no0PosA + 1;
    int expB = pointPosB >= no0PosB ? pointPosB - no0PosB : pointPosB - no0PosB + 1;
    expA = no0PosA == lena ? 0 : expA;
    expB = no0PosB == lenb ? 0 : expB;
    getBase(ba, a, no0PosA);
    getBase(bb, b, no0PosB);
    if (strcmp(ba, bb) == 0 && expA == expB) {
        printf("YES 0.%s*10^%d\n", ba, expA);
    } else {
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", ba, expA, bb, expB);
    }

    return 0;
}
