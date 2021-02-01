#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char n[2][11];
int tag, radix;

long long other2dec(char* s, int radix) {
    int len = strlen(s);
    long long ret = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            ret = ret*radix + s[i] - 'a' + 10;
        } else {
            ret = ret*radix + s[i] - '0';
        }
        if (ret < 0) {
            return -1;
        }
    }
    return ret;
}

int main() {
    scanf("%s%s%d%d", n[0], n[1], &tag, &radix);
    tag--;
    long long val = other2dec(n[tag], radix);
    int ans = -1;
    int len = strlen(n[1 - tag]);
    int maxEle = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(n[1 - tag][i])) {
            maxEle = max(maxEle, n[1 - tag][i] - 'a' + 10);
        } else {
            maxEle = max(maxEle, n[1 - tag][i] - '0');
        }
    }
    long long l = maxEle + 1, r = val + 2;
    while (l < r) {
        long long mid = (l + r) >> 1;
        long long nowVal = other2dec(n[1 - tag], mid);
        if (nowVal > val || nowVal == -1) {
            r = mid;
        } else if (nowVal < val) {
            l = mid + 1;
        } else {
            ans = mid;
            break;
        }
    }
    if (ans != -1) {
        printf("%d\n", ans);
    } else {
        printf("Impossible\n");
    }

    return 0;
}
