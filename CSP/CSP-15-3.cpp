#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const long long BASE = 256*256*256;
int n;
struct Ip {
	long long val;
	int len;
	bool operator< (const Ip& rhs) {
		if (val != rhs.val)	return val < rhs.val;
		return len < rhs.len;
	}
} ips[MAXN];

int parseNum(const string& str) {
	int ret = 0;
	for (auto& c : str) {
		ret = ret*10 + c - '0';
	}
	return ret;
}

void outputIp(Ip ip) {
	long long base = BASE;
	for (int i = 0; i < 4; i++) {
		if (i != 0)	printf("."); 
		printf("%lld", ip.val / base);
		ip.val %= base;
		base /= 256;
	}
	printf("/%d\n", ip.len);
}

long long getPrefix(long long val, int len) {
	int delta = 32 - len;
	return val >> delta;
}

bool isSubset(const Ip& a, const Ip& b) {
	long long preA = getPrefix(a.val, a.len);
	long long preB = getPrefix(b.val, a.len);
	return preA == preB;
}

Ip mergeIp(const Ip& a, const Ip& b) {
	Ip ret;
	ret.len = -1;
	long long preA = getPrefix(a.val, a.len - 1);
	long long preB = getPrefix(b.val, b.len - 1);
	if (a.len != b.len || preA != preB)	return ret;
	ret.len = a.len - 1;
	ret.val = preA << (32 - ret.len);
	return ret;
}

int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		int dotCnt = 0;
		for (int j = 0; j < str.size(); j++) {
			int k = j + 1;
			while (k < str.size() && str[k] != '.' && str[k] != '/')	k++;
			auto num = parseNum(str.substr(j, k - j));
			if (k == str.size()) {
				ips[i].val = ips[i].val*256 + num;
				ips[i].len = (dotCnt + 1)*8;
				if (dotCnt != 3) {
					for (int l = dotCnt; l < 3; l++) {
						ips[i].val *= 256;
					}
				}
			} else if (str[k] == '.') {
				dotCnt++;
				ips[i].val = ips[i].val*256 + num;
			} else {
				ips[i].val = ips[i].val*256 + num;
				ips[i].len = parseNum(str.substr(k + 1));
				if (dotCnt != 3) {
					for (int l = dotCnt; l < 3; l++) {
						ips[i].val *= 256;
					}
				}
				break;
			}
			j = k;
		}
	}
	sort(ips, ips + n);
	
	int k = 1;
	for (int i = 1; i < n; i++) {
		if (!isSubset(ips[k - 1], ips[i])) {
			ips[k++] = ips[i];
		}
	}
	int cnt = k;
	
	k = 1;
	for (int i = 1; i < cnt; i++) {
		ips[k++] = ips[i];
		while (k >= 2) {
			auto temp = mergeIp(ips[k - 2], ips[k - 1]);
			if (temp.len != -1) {
				k -= 2;
				ips[k++] = temp;
			} else {
				break;
			}
		}
	}
	cnt = k;
	
	for (int i = 0; i < cnt; i++) {
		outputIp(ips[i]);
	} 
	return 0;
} 
