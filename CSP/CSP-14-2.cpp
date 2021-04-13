#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 2020;
struct Span {
	int s, e;
} a[MAXN], b[MAXN];
int n;

int getCommon(int al, int ar, int bl, int br) {
	int l = max(al, bl);
	int r = min(ar, br);
	return max(r - l, 0);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].s, &a[i].e);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &b[i].s, &b[i].e);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += getCommon(a[i].s, a[i].e, b[j].s, b[j].e);
		}
	}
	printf("%d\n", sum);
	return 0;
}
