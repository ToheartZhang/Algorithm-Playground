#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

const int MAXN = 220;
int n, X, Y;
struct Coord {
	int x, y, id;
	int dis;
	bool operator<(const Coord& rhs) const {
		if (dis != rhs.dis)	return dis < rhs.dis;
		return id < rhs.id;
	}
} a[MAXN], peo;
priority_queue<Coord> q;
int ans[4];

int getDis(const Coord& lhs, const Coord rhs) {
	return (lhs.x  - rhs.x)*(lhs.x  - rhs.x) + (lhs.y  - rhs.y)*(lhs.y  - rhs.y);
}

int main() {
	scanf("%d%d%d", &n, &peo.x, &peo.y);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].dis = getDis(a[i], peo);
		a[i].id = i + 1;
		if (q.size() == 3) {
			if (q.top().dis > a[i].dis) {
				q.pop();
				q.push(a[i]);
			}
		} else {
			q.push(a[i]);
		}
	}
	int cnt = q.size(), tmp = q.size();
	while (!q.empty()) {
		ans[--cnt] = q.top().id;
		q.pop();
	}
	for (int i = 0; i < tmp; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
} 
