#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
int n, a[MAXN], tree[MAXN], index;

void inOrder(int root) {
    if (root >= n)
        return;
    inOrder(2*root + 1);
    tree[root] = a[index++];
    inOrder(2*root + 2);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    inOrder(0);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", tree[i]);
    }
    printf("\n");
    return 0;
}
