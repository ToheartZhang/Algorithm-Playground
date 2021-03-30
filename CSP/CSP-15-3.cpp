#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
long long BASE = 256*256*256;
int n;
struct Ip {
	long long val;
	int len;
} a[MAXN], b[MAXN], c[MAXN];
int cnt, cnt1;

bool cmp(Ip& l, Ip& r) {
	if (l.val != r.val)	return l.val < r.val;
	return l.len < r.len;
}

void output_ip(Ip ip) {
	long long base = BASE;
	for (int i = 0; i < 4; i++) {
		if (i != 0)	printf("."); 
		printf("%lld", ip.val / base);
		ip.val %= base;
		base /= 256;
	}
	printf("/%d\n", ip.len);
}

int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		int num = 0;
		long long base = BASE; 
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '.') {
				a[i].val += num*base;
				base /= 256;	
				a[i].len += 8;	
				num = 0;
				continue;
			} else if (str[j] == '/') {
				a[i].val += num*base;
				num = 0;
				base /= 256;	
				int now = 0;
				for (int k = j + 1; k < str.size(); k++) {
					now = now*10 + str[k] - '0';
				}
				a[i].len = now;
				break;
			}
			num = num*10 + str[j] - '0';
		}
		if (num != 0) {
			a[i].val += num*base;
			a[i].len += 8;
		}
//		output_ip(a[i]);
	}
	sort(a, a + n, cmp);
	
	int i = 0;
	while (i < n) {
		int j = i + 1;
		while (j < n && ((a[i].val & a[j].val) == a[i].val)) {
			j++;
		} 
		b[cnt++] = a[i];
		i = j;
	}
	
//	i = 1;
//	int j = 1;
//	c[0] = b[0];
//	while (i < cnt) {
//		if (i < cnt && c[j - 1].len == b[i].len && (c[j-1].val & b[i].val) == c[j - 1].val) {
//			c[j - 1].len--;
//			if (j == 1) {
//				j++;
//			} else {
//				j--;
//			}
//		} else {
//			
//		}
//	}
	
	for (int i = 0; i < cnt; i++) {
		output_ip(b[i]);
	}
	return 0;
}
