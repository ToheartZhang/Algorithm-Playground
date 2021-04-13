#include <cstdio>
#include <iostream>
using namespace std;

int n;
int ans[5];

bool check(int num) {
	if (num % 7 == 0)	return true;
	while (num) {
		if (num % 10 == 7)	return true;
		num /= 10;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	int i = 0, cnt = 0, now = 1;
	while (cnt < n) {
		if (check(now)) {
			ans[i]++;
		} else {
			cnt++;
		}
		now++;
		i = (i + 1) % 4;
	}
	for (int i = 0; i < 4; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
} 
