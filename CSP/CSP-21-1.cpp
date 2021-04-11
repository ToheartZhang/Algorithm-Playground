#include <cstdio>
#include <iostream>
using namespace std;

int n, sum;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s, w;
		scanf("%d%d", &s, &w);
		sum += s*w;
	}
	sum = sum > 0 ? sum : 0;
	printf("%d\n", sum);
	return 0;
} 
