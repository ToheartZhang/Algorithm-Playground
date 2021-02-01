#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int n, p;
int a[MAXN];

bool judge(int low, int high) {
    return (long long)high <= (long long)low*p;
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (judge(a[i], a[mid])) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        ans = max(ans, r - i);
    }
    printf("%d\n", ans);

    return 0;
}
