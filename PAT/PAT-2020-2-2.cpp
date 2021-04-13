#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 10010;
int n, m, cnt;
int a[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > m)   continue;
        int sum = a[i];
        cnt++;
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            if (sum > m)    break;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}