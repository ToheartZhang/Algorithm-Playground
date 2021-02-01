#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

struct Product {
    double amount;
    double price;
    double weight;
} a[MAXN];

int n;
double d;

bool cmp(Product& x, Product& y) {
    return x.weight > y.weight;
}

int main() {
    scanf("%d%lf", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i].amount);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i].price);
        a[i].weight = a[i].price / a[i].amount;
    }
    sort(a, a + n, cmp);
    int now = 0;
    double ans = 0.0;
    while (d > 0 && now < n) {
        if (a[now].amount <= d) {
            ans += a[now].price;
            d -= a[now].amount;
        } else {
            ans += a[now].weight * d;
            break;
        }
        now++;
    }
    printf("%.2lf\n", ans);

    return 0;
}
