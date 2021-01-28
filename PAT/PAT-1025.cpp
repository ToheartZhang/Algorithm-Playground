#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 30030;

struct People {
    string id;
    int grade;
    int position;
    int localRank;
    int globalRank;
} a[MAXN];

int n, k;

bool cmp(People& x, People& y) {
    if (x.grade != y.grade) {
        return x.grade > y.grade;
    }
    return x.id < y.id;
}

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            cin >> a[cnt].id;
            scanf("%d", &a[cnt].grade);
            a[cnt].position = i + 1;
            cnt++;
        }
        sort(a + cnt - k, a + cnt, cmp);
        for (int j = 0; j < k; j++) {
            int now = cnt - k + j;
            a[now].localRank = j + 1;
            if (j != 0 && a[now].grade == a[now - 1].grade) {
                a[now].localRank = a[now - 1].localRank;
            }
        }
    }
    sort(a, a + cnt, cmp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        a[i].globalRank = i + 1;
        if (i != 0 && a[i].grade == a[i - 1].grade) {
            a[i].globalRank = a[i - 1].globalRank;
        }
        cout << a[i].id;
        printf(" %d %d %d\n", a[i].globalRank, a[i].position, a[i].localRank);
    }

    return 0;
}
