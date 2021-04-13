#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 510, MAXM = 20010;
int n, m, w, q, head[MAXN], cnt, node[MAXN];
vector<vector<int>> lists;
struct Edge {
	int to, nxt;
} edges[MAXM];
struct Op {
	int t, id, from, listId;
	bool operator<(const Op& r) const {
		return t > r.t;
	}
};
priority_queue<Op> heap;

void add(int x, int y) {
	edges[cnt].to = y;
	edges[cnt].nxt = head[x];
	head[x] = cnt++;
}

void eval() {
	auto now = heap.top();
	heap.pop();
	auto& list = lists[node[now.id]];
	auto& newList = lists[now.listId];
	if (newList.size() > list.size() || (newList.size() == list.size() && newList.back() < list.back())) {
		node[now.id] = now.listId;
		for (int i = head[now.id]; ~i; i = edges[i].nxt) {
			if (edges[i].to != now.id && edges[i].to != now.from) {
				heap.push({now.t + w, edges[i].to, now.id, now.listId});
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	lists.push_back({0});
	memset(head, -1, sizeof(head));
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	scanf("%d%d", &w, &q);
	getchar();
	char str[110];
	while (q--) {
		fgets(str, 100, stdin);
		stringstream ss(str);
		int tot = 0, a[3];
		while (ss >> a[tot])	tot++;
		if (tot == 3) {
			while (!heap.empty() && heap.top().t <= a[1]) {
				eval();
			}
			lists.push_back(lists[node[a[0]]]);
			lists.back().push_back(a[2]);
			node[a[0]] = lists.size() - 1;
			for (int i = head[a[0]]; ~i; i = edges[i].nxt) {
				if (edges[i].to != a[0]) {
					heap.push({a[1] + w, edges[i].to, a[0], node[a[0]]});
				}
			}
		} else {
			while (!heap.empty() && heap.top().t <= a[1]) {
				eval();
			}
			printf("%d ", lists[node[a[0]]].size());
			for (auto& item : lists[node[a[0]]]) {
				printf("%d ", item);
			}
			printf("\n");
		}
	}
	return 0;
}
