    #include <cstdio>
    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    const int MAXN = 100010;

    struct Node {
        int val;
        int nxt;
    } a[MAXN];

    int start, n, k;
    int order[MAXN], temp[MAXN], cnt;
    vector<int> vecOrder;

    void reverse(int l, int r) {
        int mid = (r - l) / 2;
        for (int i = 0; i < mid; i++) {
            swap(order[l + i], order[r - i - 1]);
        }
    }

    int main() {
        scanf("%d%d%d", &start, &n, &k);
        for (int i = 0; i < n; i++) {
            int addr;
            scanf("%d", &addr);
            scanf("%d%d", &a[addr].val, &a[addr].nxt);
        }
        int now = start;
        while (now != -1) {
            order[cnt++] = now;
            now = a[now].nxt;
        }
        for (int times = 0; times < cnt / k; times++) {
            reverse(times*k, (times + 1)*k);
        }
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ", order[i], a[order[i]].val);
            if (i == cnt - 1) {
                printf("-1\n");
            } else {
                printf("%05d\n", order[i + 1]);
            }
        }

        return 0;
    }
