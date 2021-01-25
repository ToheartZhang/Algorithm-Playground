#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, minLen = INF, pos = -1;
string a[110];

int myReverse(string& str) {
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        swap(str[i], str[len - i - 1]);
    }
    return len;
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
        int nowLen = myReverse(a[i]);
        minLen = min(nowLen, minLen);
    }
    for (int i = 0; i < minLen; i++) {
        char nowC = a[0][i];
        bool isEqual = true;
        for (int j = 1; j < n; j++) {
            if (nowC != a[j][i]) {
                isEqual = false;
                break;
            }
        }
        if (!isEqual) {
            break;
        } else {
            pos = i;
        }
    }
    if (pos == -1) {
        printf("nai\n");
    } else {
        for (int i = pos; i >= 0; i--) {
            printf("%c", a[0][i]);
        }
        printf("\n");
    }

    return 0;
}
