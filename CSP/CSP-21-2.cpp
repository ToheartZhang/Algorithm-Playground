#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXM = 100010;
struct Stu {
	int y, r;
} a[MAXM];
int sum[MAXM];
int m, ansY;
long long ans;

bool cmp(const Stu& p, const Stu& q) {
	if (p.y != q.y)	return p.y > q.y;
	return p.r < q.r;
}

int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i].y, &a[i].r);
	}
	sort(a, a + m, cmp);
	for (int i = 0; i < m; i++) {
		if (i == 0)	sum[i] = a[i].r;
		else	sum[i] = sum[i - 1] + a[i].r;
	}
	for (int i = 0; i < m; i++) {
		int leftPred = sum[i], rightPred = sum[m - 1] - sum[i];
		long long res = leftPred + m - i - 1 - rightPred;
		if (res > ans) {
			ans = res;
			ansY = a[i].y;
		} 
	}
	printf("%d\n", ansY);
	return 0;
}
