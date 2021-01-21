/* 
 * Description: Return product of polynomial a and b
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

const int MAXN = 2010;

double coef[MAXN];
vector<pair<int, double>> ans;
vector<pair<int, double>> a[2];

int main() {
    for (int i = 0; i < 2; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int x;
            double y;
            scanf("%d%lf", &x, &y);
            a[i].push_back(make_pair(x, y));
        }
    }

    for (auto& item1 : a[0]) {
        for (auto& item2 : a[1]) {
            coef[item1.first + item2.first] += item1.second*item2.second;
        }
    }
    
    int times = 0;
    for (int i = 2000; i >= 0; i--) {
        if (fabs(coef[i]) > 1e-6) {
            times++;
            ans.push_back(make_pair(i, coef[i]));
        }
    }
    printf("%d", times);
    for (auto& item : ans) {
        printf(" %d %.1lf", item.first, item.second);
    }
    printf("\n");

    return 0;
}
