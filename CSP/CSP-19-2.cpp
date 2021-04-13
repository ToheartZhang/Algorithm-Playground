#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500010;
typedef long long LL;
typedef pair<int, LL> PII;
int n, a, b;
PII x[MAXN], y[MAXN];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < a; i++) {
		scanf("%d%lld", &x[i].first, &x[i].second);
	}
	for (int i = 0; i < b; i++) {
		scanf("%d%lld", &y[i].first, &y[i].second);
	}
	sort(x, x + a);
	sort(y, y + b);
	int i = 0, j = 0;
	LL ans = 0;
	while (i < a && j < b) {
		if (x[i].first == y[j].first) {
			ans += x[i].second*y[j].second;
			i++;
			j++;
		} else if (x[i].first > y[j].first) {
			j++;
		} else {
			i++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
