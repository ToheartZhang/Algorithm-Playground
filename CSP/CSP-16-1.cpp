#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int n;
int a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	printf("%d", a[n - 1]);
	if (n & 1) {
		printf(" %d", a[n / 2]);
	} else {
		double result = (a[n / 2] + a[n / 2 - 1]) / 2.0;
		if (result == (double)(int)result) {
			printf(" %d", (int)result);
		} else {
			printf(" %.1f", result);
		}
	}
	printf(" %d\n", a[0]);
	return 0;
} 
