#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 13;

struct Node {
    char name[MAXN];
    char password[MAXN];
    bool isChange;
} a[1010];

int n, cnt;

bool modify(char &c) {
    bool ret = false;
    if (c == '1') {
        c = '@';
        ret = true;
    } else if (c == '0') {
        c = '%';
        ret = true;
    } else if (c == 'l') {
        c = 'L';
        ret = true;
    } else if (c == 'O') {
        c = 'o';
        ret = true;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s", a[i].name, a[i].password);
        int len = strlen(a[i].password);
        for (int j = 0; j < len; j++) {
            a[i].isChange |= modify(a[i].password[j]);
        }
        if (a[i].isChange) {
            cnt++;
        }
    }
    if (!cnt) {
        if (n == 1) {
            printf("There is 1 account and no account is modified\n");
        } else {
            printf("There are %d accounts and no account is modified\n", n);
        }
    } else {
        printf("%d\n", cnt);
        for (int i = 0; i < n; i++) {
            if (a[i].isChange) {
                printf("%s %s\n", a[i].name, a[i].password);
            }
        }
    }

    return 0;
}
