#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 40040;
const int MAXM = 110;

struct People {
    int id;
    int gradeE;
    int gradeI;
    int grade;
    int prefer[7];
    int rank;
} a[MAXN];

struct School {
    int quota;
    int cnt;
    int lowRank;
    vector<int> stus;
} s[MAXM];

int n, m, k;

bool cmp(People& x, People& y) {
    if (x.grade != y.grade) {
        return x.grade > y.grade;
    }
    return x.gradeE > y.gradeE;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &s[i].quota);
    }
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        scanf("%d%d", &a[i].gradeE, &a[i].gradeI);
        a[i].grade = (a[i].gradeE + a[i].gradeI) / 2;
        for (int j = 0; j < k; j++) {
            scanf("%d", &a[i].prefer[j]);
        }
    }
    sort(a, a + n, cmp);
    int lst = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && a[i].grade == a[i-1].grade && a[i].gradeE == a[i-1].gradeE) {
            a[i].rank = lst;
        } else {
            a[i].rank = i;
            lst = i;
        }
        for (int j = 0; j < k; j++) {
            int nowSch = a[i].prefer[j];
            if (s[nowSch].cnt < s[nowSch].quota || s[nowSch].lowRank == a[i].rank) {
                s[nowSch].cnt++;
                s[nowSch].lowRank = a[i].rank;
                s[nowSch].stus.push_back(a[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        sort(s[i].stus.begin(), s[i].stus.end());
        for (int j = 0; j < s[i].cnt; j++) {
            printf("%d", s[i].stus[j]);
            if (j != s[i].cnt - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}