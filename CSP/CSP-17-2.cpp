#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1010;
bool isDrop[MAXN];
int n, sum;

int getId(int id) {
	return (id + n) % n;
}

bool check(int x, int y, int z) {
	return isDrop[x] && isDrop[y] && isDrop[z];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int m, num;
		scanf("%d%d", &m, &num);
		for (int j = 1; j < m; j++) {
			int op;
			scanf("%d", &op);
			if (op > 0) {
				if (num != op) {
					isDrop[i] = true;
					num = op;
				}
			} else {
				num += op;
			}
		}
		sum += num;
	}
	int dropGroupCnt = 0, dropCnt = 0;
	for (int i = 0; i < n; i++) {
		if (check(getId(i - 1), getId(i), getId(i + 1))) {
			dropGroupCnt++;
		}
		if (isDrop[i]) 	dropCnt++;
	}
	printf("%d %d %d\n", sum, dropCnt, dropGroupCnt);
	return 0;
} 
