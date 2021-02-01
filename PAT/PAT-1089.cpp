#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 110;

int n;
int a[MAXN], b[MAXN], c[MAXN], tmp[MAXN];

bool isSame(int* a, int* b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void showArr(int* arr) {
    for (int k = 0; k < n; k++) {
        if (k != 0) {
            printf(" ");
        }
        printf("%d", arr[k]);
    }
    printf("\n");
}

void merge(int *arr, int l, int r, int mid) {
    memset(tmp, 0, sizeof(tmp));
    int i = l, j = mid, idx = 0;
    while (i < mid && j < r) {
        if (i < mid && arr[i] <= arr[j]) {
            tmp[idx++] = arr[i++];
        } else {
            tmp[idx++] = arr[j++];
        }
    }
    while (i < mid) {
        tmp[idx++] = arr[i++];
    }
    while (j < r) {
        tmp[idx++] = arr[j++];
    }
    for (int k = 0; k < r - l; k++) {
        arr[k + l] = tmp[k];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    bool lst = false;
    for (int i = 1; i < n; i++) {
        int temp = c[i];
        int j = i - 1;
        while (j >= 0 && temp < c[j]) {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = temp;
        if (lst) {
            printf("Insertion Sort\n");
            showArr(c);
            return 0;
        }
        lst = isSame(c, b);
    }

    printf("Merge Sort\n");
    lst = false;
    for (int step = 2; step/2 <= n; step *= 2) {
        for (int i = 0; i < n; i += step) {
            merge(a, i, min(i + step, n), i + step / 2);
        }
        // showArr(a);
        if (lst) {
            showArr(a);
            return 0;
        }
        lst = isSame(a, b);
    }

    return 0;
}