#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1010;
int n;
int a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		int sum = a[i];
		if (i == 0) {
			sum += a[i + 1];
			sum /= 2;
		} else if (i == n - 1) {
			sum += a[i - 1];
			sum /= 2;
		} else {
			sum += (a[i - 1] + a[i + 1]);
			sum /= 3;
		}
		printf("%d ", sum);
	}
	printf("\n");
	return 0;
}
