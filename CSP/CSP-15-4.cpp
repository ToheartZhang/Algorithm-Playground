#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50010, MAXM = 100010;
int n, m;
int fa[MAXN];

struct Edge {
	int x, y, z;
	bool operator<(const Edge& rhs) const {
		return z < rhs.z;
	}
} edges[MAXM];

int find(int x){
	if (x != fa[x])	fa[x] = find(fa[x]);
	return fa[x]; 
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)	fa[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edges[i] = {x, y, z};
	}
	sort(edges, edges + m);
	int res = 0;
	for (int i = 0; i < m; i++) {
		int x = edges[i].x, y = edges[i].y, z = edges[i].z;
		if (find(x) != find(y)) {
			fa[find(x)] = find(y);
			res = z;
		}
	}
	printf("%d\n", res);
	return 0;
} 
