#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct People {
    string name;
    int age;
    int wealth;
} a[MAXN];

int n, k;

bool cmp(People& x, People& y) {
    if (x.wealth != y.wealth) {
        return x.wealth > y.wealth;
    } else if (x.age != y.age) {
        return x.age < y.age;
    }
    return x.name < y.name;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> a[i].name;
        scanf("%d%d", &a[i].age, &a[i].wealth);
    }
    sort(a, a + n, cmp);
    for (int j = 1; j <= k; j++) {
        int num, low, high, cnt = 0;
        scanf("%d%d%d", &num, &low, &high);
        printf("Case #%d:\n", j);
        for (int i = 0; i < n; i++) {
            if (a[i].age >= low && a[i].age <= high) {
                cnt++;
                cout << a[i].name;
                printf(" %d %d\n", a[i].age, a[i].wealth);
            }
            if (cnt == num) {
                break;
            }
        }
        if (cnt == 0) {
            printf("None\n");
        }
    }

    return 0;
}
