#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 110, MAXM = 2021;
int n, m;
double r;
double o[MAXN], p[MAXM][MAXN], disPO[MAXM], rDisPO[MAXM];
double ans[MAXM];

inline double sqr(double x) {
	return x*x;
}

int main() {
	scanf("%d%d%lf", &n, &m, &r);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &o[i]);
	}
	for (int i = 0; i < m; i++) {
		double s = 0;
		for (int j = 0; j < n; j++) {
			scanf("%lf", &p[i][j]);
			s += sqr(p[i][j] - o[j]);
		}
		disPO[i] = sqrt(s);
		rDisPO[i] = sqrt(s - sqr(r));
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) {
			double s = 0;
			for (int k = 0; k < n; k++)	s += sqr(p[i][k] - p[j][k]);
			double c = sqrt(s), a = disPO[i], b = disPO[j];
			double p = (a + b + c) / 2;
			double area = sqrt(p*(p-a)*(p-b)*(p-c));
			double h = 2*area / c;
			if (h >= r || sqr(b) >= sqr(a) + s || sqr(a) >= sqr(b) + s) {
				ans[i] += c;
				ans[j] += c;
				continue;
			}
			double angle1 = acos((sqr(a) + sqr(b) - s) / (2*a*b));
			double angle2 = acos(r / a);
			double angle3 = acos(r / b);
			double t = (angle1 - angle2 - angle3)*r + rDisPO[i] + rDisPO[j];
			ans[i] += t;
			ans[j] += t;
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%.12lf\n", ans[i]);
	}
	return 0;
}
