#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10010;
int n;
int sum = 0, cur = 0, minW = INF, nowCnt = 0;
int a[MAXN];
int dif[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i != 0) {
            if (a[i - 1] < a[i]) {
                dif[i] = dif[i - 1] + 1;
            } else if (a[i - 1] > a[i]) {
                for (int j = i - 1; j >= 0; j--) {
                    if (a[j] > a[j + 1] && dif[j] <= dif[j + 1]) {
                        dif[j] = dif[j + 1] + 1;
                    } else if (a[j] == a[j + 1] && dif[j] < dif[j + 1]) {
                        dif[j] = dif[j + 1];
                    }
                }
            } else {
                dif[i] = dif[i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        sum += dif[i];
    }
    printf("%d\n", sum*100 + n*200);
    return 0;
}