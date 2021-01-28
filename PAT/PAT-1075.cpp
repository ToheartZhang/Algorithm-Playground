#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

struct People {
    int id;
    int score[5];
    int allSolve;
    int sum;
    bool isShow;
} a[MAXN];

bool cmp(People& x, People& y) {
    if (x.isShow != y.isShow) {
        return x.isShow > y.isShow;
    } else if (x.sum != y.sum) {
        return x.sum > y.sum;
    } else if (x.allSolve != y.allSolve) {
        return x.allSolve > y.allSolve;
    }
    return x.id < y.id;
}

int n, k, m;
int weight[6];

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        a[i].id = i;
        for (int j = 1; j <= k; j++) {
            a[i].score[j] = -2;
        }
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; i++) {
        int id, problem, score;
        scanf("%d%d%d", &id, &problem, &score);
        if (score > a[id].score[problem]) {
            a[id].score[problem] = score;
            if (score == weight[problem]) {
                a[id].allSolve++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (a[i].score[j] > -1) {
                a[i].sum += a[i].score[j];
                a[i].isShow = true;
            }
        }
    }
    sort(a + 1, a + n + 1, cmp);
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i].isShow) {
            break;
        }
        if (i != 1 && a[i].sum == a[i - 1].sum) {
            printf("%d ", lst);
        } else {
            printf("%d ", i);
            lst = i;
        }
        printf("%05d %d", a[i].id, a[i].sum);
        for (int j = 1; j <= k; j++) {
            if (a[i].score[j] > -1) {
                printf(" %d", a[i].score[j]);
            } else if (a[i].score[j] == -1) {
                printf(" 0");
            } else {
                printf(" -");
            }
        }
        printf("\n");
    }

    return 0;
}
