    #include <cstdio>
    #include <iostream>
    using namespace std;

    const int MAXN = 100010;

    struct Node {
        char val;
        int nxt;
        bool flag;
    } a[MAXN];

    int start1, start2, n;

    int main() {
        scanf("%d%d%d", &start1, &start2, &n);
        for (int i = 0; i < n; i++) {
            int addr;
            scanf("%d", &addr);
            scanf(" %c %d", &a[addr].val, &a[addr].nxt);
        }
        while (start1 != -1) {
            a[start1].flag = true;
            start1 = a[start1].nxt;
        }
        while (start2 != -1) {
            if (a[start2].flag) {
                printf("%05d\n", start2);
                return 0;
            }
            start2 = a[start2].nxt;
        }
        printf("-1\n");

        return 0;
    }
