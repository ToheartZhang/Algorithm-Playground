#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int a[MAXN];
int n;

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a[num] = i;
        if (i != 0 && a[i] != i) {
            cnt++;
        }
    }
    int ans = 0;
    int k = 1;
    while (cnt > 0) {
        if (a[0] == 0) {
            while (k < n) {
                if (a[k] != k) {
                    swap(a[0], a[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while (a[0] != 0) {
            swap(a[0], a[a[0]]);
            cnt--;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
