#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 1010;

int m, n, k;
int a[MAXN];
stack<int> stk;

int main() {
    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int pos = 0;
        int num = 1;
        while (pos < n) {
            while (num <= a[pos] && stk.size() < m) {
                stk.push(num++);
            }
            if (stk.top() != a[pos]) {
                printf("NO\n");
                break;
            }
            stk.pop();
            pos++;
        }
        if (pos == n) {
            printf("YES\n");
        }
    }

    return 0;
}
