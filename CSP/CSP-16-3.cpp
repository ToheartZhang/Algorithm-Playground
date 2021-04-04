#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned int UI;
const int MAXN = 1010, MAXM = 40*1024*8;
int disk[MAXN][MAXM / 4];
bool ok[MAXN];
int n, s, l, m, blockCnt;

int toDecimal(char c) {
	if (c >= '0' && c <= '9')	return c - '0';
	return c - 'A' + 10;
}

int getDiskId(int k, int blockId) {
	
}

string getContent() {
	
}

int main() {
	scanf("%d%d%d", &n, &s, &l);
	for (int k = 0; k < l; k++) {
		int id;
		string str;
		scanf("%d", &id);
		ok[id] = true;
		cin >> str;
		blockCnt = str.size() / 8;
		for (int i = 0; i < str.size(); i += 8) {
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
		if (id > blockCnt*(n - 1)) {
			puts("-");
			continue;
		}
		int k = id / s;
		int distId = id % n;
		if (ok[distId]) {
			
		}
	}
}
