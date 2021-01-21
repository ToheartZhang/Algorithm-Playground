/* 
 * Description: Return sum of polynomial a and b
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 1010;

double coef[MAXN];
vector<pair<int, double>> ans;

int main() {
    for (int i = 0; i < 2; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int x;
            double y;
            scanf("%d%lf", &x, &y);
            coef[x] += y;
        }
    }
    int times = 0;
    for (int i = 1000; i >= 0; i--) {
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