#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2020;
const int MAX_ID = 1000010;
const char COURSE[4] = {'A', 'C', 'M', 'E'};

struct Node {
    int id, best;
    int grade[4], rank[4];
} a[MAXN];

int n, m, pos;
int cur[MAX_ID];

bool cmp(Node& x, Node& y) {
    return x.grade[pos] > y.grade[pos];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a[i].id, &a[i].grade[1], &a[i].grade[2], &a[i].grade[3]);
        a[i].grade[0] = (a[i].grade[1] + a[i].grade[2] + a[i].grade[3]) / 3;
    }
    for (pos = 0; pos < 4; pos++) {
        sort(a, a + n, cmp);
        for (int j = 0; j < n; j++) {
            a[j].rank[pos] = j + 1;
            if (j >= 1 && a[j].grade[pos] == a[j - 1].grade[pos]) {
                a[j].rank[pos] = a[j - 1].rank[pos];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cur[a[i].id] = i + 1;
        int minn = a[i].rank[0];
        a[i].best = 0;
        for (int j = 1; j < 4; j++) {
            if (a[i].rank[j] < minn) {
                a[i].best = j;
                minn = a[i].rank[j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        int num = cur[id] - 1;
        if (num == -1) {
            printf("N/A\n");
        } else {
            printf("%d %c\n", a[num].rank[a[num].best], COURSE[a[num].best]);
        }
    }

    return 0;
}
