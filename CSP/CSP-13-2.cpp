#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 110;
int n, l, t;
int a[MAXN], dir[MAXN];

int main() {
	scanf("%d%d%d", &n, &l, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		dir[i] = 1;
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] == 0 || a[j] == l) {
				dir[j] *= -1;
			}
			for (int k = 0; k < j; k++) {
				if (a[k] == a[j] && dir[k] != dir[j]) {
					dir[k] *= -1;
					dir[j] *= -1;
				}
			}
		}
		for (int j = 0; j < n; j++) {
			a[j] = a[j] + dir[j];
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
