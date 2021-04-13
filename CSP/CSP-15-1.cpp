#include <cstdio>
#include <iostream>
using namespace std;

int r, y, g, n;

int main() {
	int sum = 0;
	scanf("%d%d%d%d", &r, &y, &g, &n);
	for (int i = 0; i < n; i++) {
		int k, t;
		scanf("%d%d", &k, &t);
		if (k == 0) {
			sum += t;
		} else if (k == 1) {
			sum += t;
		} else if (k == 2) {
			sum += (t + r);
		}
	}
	printf("%d\n", sum);
	return 0;
}
