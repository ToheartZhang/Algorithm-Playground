#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 0;
int n, m, maxGet, maxGetId, sum;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		int temp = num;
		for (int j = 0; j < m; j++) {
			int delta;
			scanf("%d", &delta);
			num += delta;
		}
		int get = temp - num;
		if (maxGet < get) {
			maxGetId = i + 1;
			maxGet = get;
		}
		sum += num;
	}
	printf("%d %d %d\n", sum, maxGetId, maxGet);
	return 0;
} 
