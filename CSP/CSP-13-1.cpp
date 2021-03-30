#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int a;
	int sum = 0;
	int centerCnt = 0;
	while (scanf("%d", &a) && a != 0) {
		if (a == 1) {
			sum++;
			centerCnt = 0;
		} else {
			centerCnt++;
			sum += 2*(centerCnt);
		}
	}
	printf("%d\n", sum);
	return 0;
}
