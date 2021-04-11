#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned int UI;
const int MAXN = 1010, MAXM = 40*1024*8 + 10;
UI disk[MAXN][MAXM / 8];
bool ok[MAXN];
char str[MAXM];
int n, s, l, m, blockCnt;

inline int toDecimal(char c) {
	if (c >= '0' && c <= '9')	return c - '0';
	return c - 'A' + 10;
}

inline char toX(int x) {
	if (x > 9) {
		return x - 10 + 'A';
	} else {
		return x + '0';
	}
}

inline void getContent(UI num) {
	string ret;
	for (int i = 7; i >= 0; i--) {
		ret += toX(num >> (i << 2) & 15);
	}
	puts(ret.c_str());
}

int main() {
	scanf("%d%d%d", &n, &s, &l);
	for (int k = 0; k < l; k++) {
		int id;
		scanf("%d", &id);
		getchar();
		ok[id] = true;
		fgets(str, MAXM, stdin);
		int len = strlen(str) - 1;
		blockCnt = len / 8;
		for (int i = 0; i < len; i += 8) {
			UI content = 0; 
			for (int j = 0; j < 8; j++) {
				content = (content << 4) + toDecimal(str[i + j]);
			}
			disk[id][i >> 3] = content;
		}
	}
	scanf("%d", &m);
	while (m--) {
		int id;
		scanf("%d", &id);
		if (id >= blockCnt*(n - 1)) {
			puts("-");
			continue;
		}
		int stripId = id / s;
		int stripRow = stripId / (n - 1);
		int stripCol = stripId % (n - 1);
		int blockId = stripRow*s + id % s;
		int diskId = (stripCol + 1 + (n - 1 - stripRow) + n) % n;
		if (ok[diskId]) {
			UI num = disk[diskId][blockId];
			getContent(num); 
		} else if (l == n - 1) {
			UI now = 0;
			for (int j = 0; j < n; j++) {
				now ^= disk[j][blockId];
			}
			getContent(now);
		} else {
			puts("-");
		}
	}
	return 0;
}
