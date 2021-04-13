#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

const int MAXN = 1010*6, MAXS = 10010;
const string OPERA[] = {"NOT", "AND", "OR", "XOR", "NAND", "NOR"};
int q, n, m, cnt;
struct Edge {
	int to, nxt;
} edges[MAXN];
char str[100];
int head[MAXN], ops[MAXN], ind[MAXN];
vector<int> inputs[MAXS], outputs[MAXS], order;
int realOut[MAXN]; 
map<string, int> opMap;

void init() {
	memset(head, -1, sizeof(head));
	memset(ind, 0, sizeof(ind));
	memset(realOut, 0, sizeof(realOut));
	memset(ops, 0, sizeof(ops));
	order.clear();
}

void addE(int a, int b) {
	edges[cnt].to = b;
	edges[cnt].nxt = head[a];
	head[a] = cnt++;
	ind[b]++; 
}

int NOT(int a, int b) {
	return !b;
}
int AND(int &a, int b) {
	return a & b;
}
int OR(int a, int b) {
	return a | b;
}
int XOR(int a, int b) {
	return a ^ b;
}
int NAND(int a, int b) {
	return a | !b;
}
int NOR(int a, int b) {
	return a & !b;
}
int op(int a, int b, int id) {
	if (id == 0)	return NOT(a, b);
	if (id == 1)	return AND(a, b);
	if (id == 2)	return OR(a, b);
	if (id == 3)	return XOR(a, b);
	if (id == 4)	return NAND(a, b);
	return NOR(a, b);
}

bool topSort() {
	queue<int> q;
	int tot = 0;
	for (int i = 1; i <= n + m; i++) {
		if (!ind[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		order.push_back(now);
		tot++;
		q.pop();
		for (int i = head[now]; ~i; i = edges[i].nxt) {
			int to = edges[i].to;
			if (--ind[to] == 0) {
				q.push(to);
			}
		}
	}
	return tot == n + m;
}

int main() {
	for (int i = 0; i < 6; i++) {
		opMap[OPERA[i]] = i;
	}
	scanf("%d", &q);
	while (q--) {
		init();
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			ops[i] = opMap[str];
			int k;
			scanf("%d", &k);
			for (int j = 0; j < k; j++) {
				scanf("%s", str);
				int num = atoi(str + 1);
				if (str[0] == 'I') {
					addE(num + n, i);
				} else {
					addE(num, i);
				}
			}
		}
		int s;
		scanf("%d", &s);
		for (int i = 0; i < s; i++) {
			inputs[i].clear();
			for (int j = 0; j < m; j++) {
				int input;
				scanf("%d", &input);
				inputs[i].push_back(input);	
			}
		}
		for (int i = 0; i < s; i++) {
			outputs[i].clear();
			int num;
			scanf("%d", &num);
			while (num--) {
				int output;
				scanf("%d", &output);
				outputs[i].push_back(output);	
			}
		}  
		if (!topSort()) {
			puts("LOOP");
			continue;	
		}
		
		for (int i = 0; i < s; i++) {
			for (int j = 1; j <= n; j++) {
				if (ops[j] == 1 || ops[j] == 5) {
					realOut[j] = 1;
				} else {
					realOut[j] = 0;
				} 
			}
			for (int j = 1; j <= m; j++) {
				realOut[j + n] = inputs[i][j-1];
			}
			for (auto& j : order) {
				for (int l = head[j]; ~l; l = edges[l].nxt) {
					int to = edges[l].to;
					realOut[to] = op(realOut[to], realOut[j], ops[to]);
				}
			}
			for (auto& id : outputs[i]) {
				printf("%d ", realOut[id]);
			}
			printf("\n");
		}
	}
	return 0;
}
