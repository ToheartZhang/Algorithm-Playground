#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
const int MAXN = 1010;
int n, m;
struct Point {
	LL x, y;
	char t;
} p[MAXN];

LL calculate(int a, int b, int c, Point& p) {
	return a + b*p.x + c*p.y;
}

int isConsis(int a, int b, int c, char t) {
	int lst = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].t == t) {
			auto res = calculate(a, b, c, p[i]);
			if (lst != 0 && res * lst <= 0) {
				return 2;
			}
			lst = res > 0 ? 1 : -1;
		}
	}
	return lst;
}

bool check(int a, int b, int c) {
	auto res1 = isConsis(a, b, c, 'A'), res2 = isConsis(a, b, c, 'B');
	if (res1 == 2 || res2 == 2)	return false;
	return res1 != res2;
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld %c", &p[i].x, &p[i].y, &p[i].t);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (check(a, b, c))	puts("Yes");
		else	puts("No");
	}
	return 0;
}
