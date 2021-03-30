#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1010;
int n;
int a[MAXN];
int minDiff = 0x3f3f3f3f;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			minDiff = min(abs(a[i] - a[j]), minDiff);
		}
	}
	printf("%d\n", minDiff);
	
	return 0;
}
