#include <cstdio>
#include <iostream>
using namespace std;

int n, k, t, xl, yl, xr, yr;
int ansStay, ansBy;

bool isInside(const int x, const int y) {
	return (x >= xl && x <= xr) && (y >= yl && y <= yr);
}

int main() {
	scanf("%d%d%d%d%d%d%d", &n, &k, &t, &xl, &yl, &xr, &yr);
	for (int i = 0; i < n; i++) {
		bool nowBy = false;
		int nowStay = 0;
		int cnt = 0;
		for (int j = 0; j < t; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (isInside(x, y)) {
				nowBy = true;
				cnt++;
			} else if (cnt) {
				nowStay = max(nowStay, cnt);
				cnt = 0;
			}
		}
		nowStay = max(nowStay, cnt);
		if (nowStay >= k)	ansStay++;
		if (nowBy)	ansBy++;
	}
	printf("%d\n%d\n", ansBy, ansStay);
	return 0;
}
