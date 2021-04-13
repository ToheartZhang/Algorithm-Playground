#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 3030;
int n, a[MAXN], b[MAXN], f[MAXN][MAXN], ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        int maxv = 1;   // 所有满足 a[i] > b[j] 时的 f[i][j] + 1 的最大值
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];  // 不以 a[i] 结尾
            if (a[i] == b[j])   f[i][j] = max(f[i][j], maxv);
            if (a[i] > b[j])    maxv = max(maxv, f[i][j] + 1);
        }
    }
    for (int i = 1; i <= n; i++)    ans = max(f[n][i], ans);
    printf("%d\n", ans);
    return 0;
}