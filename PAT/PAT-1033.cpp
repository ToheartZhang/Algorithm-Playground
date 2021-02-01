#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 300030;

struct Station {
    double price;
    double dis;
} a[MAXN];

double c, dis, unitDis;
int n;

bool cmp(Station& x, Station& y) {
    return x.dis < y.dis;
}

int main() {
    scanf("%lf%lf%lf%d", &c, &dis, &unitDis, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &a[i].price, &a[i].dis);
    }
    a[n].price = 0;
    a[n++].dis = dis;
    sort(a, a + n, cmp);
    if (a[0].dis != 0.0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int now = 0;
    double nowTank = 0, ans = 0;
    while (now < n - 1) {
        int minSta = -1;
        double minPrice = INF;
        double nowDisMax = a[now].dis + c*unitDis;
        for (int i = now + 1; i < n && a[i].dis <= nowDisMax; i++) {
            if (a[i].price < minPrice) {
                minPrice = a[i].price;
                minSta = i;
                if (minPrice < a[now].price) {
                    break;
                }
            }
        }
        if (minSta == -1) {
            break;
        }
        double delta = (a[minSta].dis - a[now].dis) / unitDis;
        if (minPrice < a[now].price) {
            if (nowTank < delta) {
                ans += (delta - nowTank)*a[now].price;
                nowTank = 0;
            } else {
                nowTank -= delta;
            }
        } else {
            ans += (c - nowTank)*a[now].price;
            nowTank = c - delta;
        }
        now = minSta;
    }
    if (now != n - 1) {
        printf("The maximum travel distance = %.2lf\n", a[now].dis + c*unitDis);
    } else {
        printf("%.2lf\n", ans);
    }

    return 0;
}
