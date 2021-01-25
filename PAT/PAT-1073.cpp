#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10010;

char a[MAXN];
int exp = 0;

int main() {
    scanf("%s", a);
    int len = strlen(a);
    if (a[0] == '-') {
        printf("-");
    }
    int pos = 0;
    while (a[pos] != 'E') {
        pos++;
    }
    pos++;
    bool negExpFlag = false;
    if (a[pos] == '-') {
        negExpFlag = true;
    }
    for (pos++; pos < len; pos++) {
        exp = (a[pos] - '0') + exp*10;
    }
    if (negExpFlag) {
        if (exp != 0) {
            printf("0.");
            for (int i = 0; i < exp - 1; i++) {
                printf("0");
            }
        }
        
        for (int i = 1; i < len; i++) {
            if (a[i] == '.' && exp != 0) {
                continue;
            }
            if (a[i] == 'E') {
                break;
            }
            printf("%c", a[i]);
        }
        printf("\n");
    } else {
        exp++;
        for (int i = 1; i < len; i++) {
            if (a[i] == '.') {
                continue;
            }
            if (a[i] == 'E') {
                break;
            }
            if (exp == 0) {
                printf(".");   
            }
            exp--;
            printf("%c", a[i]);
        }
        for (int i = 0; i < exp; i++) {
            printf("0");
        }
        printf("\n");
    }
    
    return 0;
}
