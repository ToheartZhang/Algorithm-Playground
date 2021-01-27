#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct People {
    int id;
    string name;
    int score;
} a[MAXN];

int n, c;

bool cmp(People& x, People& y) {
    if (c == 1 && x.name != y.name) {
        return x.name < y.name;
    } else if (c == 2 && x.score != y.score) {
        return x.score < y.score;
    }
    return x.id < y.id;
}

int main() {
    scanf("%d%d", &n, &c);
    c--;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].id);
        cin >> a[i].name;
        scanf("%d", &a[i].score);
    }
    sort(a, a + n, cmp);
    for (int i= 0; i < n; i++) {
        printf("%06d ", a[i].id);
        cout << a[i].name;
        printf(" %d\n", a[i].score);
    }

    return 0;
}
