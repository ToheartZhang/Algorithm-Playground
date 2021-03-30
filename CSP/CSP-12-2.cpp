#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1010;
int a[MAXN];
int n, k, nown;
bool isOut[MAXN];

bool judge(int cnt) {
	return (cnt % k == 0) || (cnt % 10 == k);
}

int getFinish() {
	for (int i = 0; i < n; i++) {
		if (!isOut[i])	return i + 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	nown = n;
	int now = 0;
	int cnt = 1;
	while (1) {
		if (isOut[now]) {
			now = (now + 1) % n;
			continue;
		}	
		if (judge(cnt)) {
			isOut[now] = 1;
			nown--;
		}
		now = (now + 1) % n;
		cnt++;
		if (nown == 1) {
			printf("%d\n", getFinish());
			return 0;
		}
	} 
	return 0;
}
