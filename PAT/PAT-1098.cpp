#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 110;
int n;
int a[MAXN], b[MAXN];

void downAdjust(int l, int r) {
    int root = 0, son = root*2 + 1;
    while (son < r) {
        if (son + 1 < r && b[son] < b[son + 1]) son++;
        if (b[root] >= b[son])  break;
        swap(b[root], b[son]);
        root = son;
        son = root*2 + 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int idx = 1;
    while (idx < n && b[idx - 1] <= b[idx]) idx++;
    int nidx = idx;
    while (idx < n && b[idx] == a[idx]) idx++;
    if (idx == n) {
        printf("Insertion Sort\n");
        int temp = a[nidx], j = nidx - 1;
        for (; j >= 0; j--) {
            if (b[j] > temp) {
                b[j + 1] = b[j];
            } else {
                break;
            }
        }
        b[j + 1] = temp;
    } else {
        printf("Heap Sort\n");
        idx = n - 1;
        while (idx >= 0 && b[0] < b[idx])   idx--;
        swap(b[0], b[idx]);
        downAdjust(0, idx);
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", b[i]);
    }
    printf("\n");

    return 0;
}
