#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 110;
struct Rule {
	string p;
	string r;
} a[MAXN];
int n, m;

string get_num(string& str) {
	string ret;
	for (auto& c : str) {
		if (c >= '0' && c <= '9') {
			ret += c;
		} else {
			ret.clear();
			return ret;
		}
	}
	int i = 0;
	for (; i + 1 < ret.size(); i++) {
		if (ret[i] != '0') {
			break;
		}
	}
	return ret.substr(i);
}

vector<string> match(string& p, string& str) {
	vector<string> ret(1);
	int i = 1, j = 1;
	while (i < p.size() && j < str.size()) {
		int u = i + 1, v = j + 1;
		while (u < p.size() && p[u] != '/')	u++;
		while (v < str.size() && str[v] != '/')	v++;
		string subp = p.substr(i, u - i);
		string substr = str.substr(j, v - j);
		if (subp == "<int>") {
			auto num = get_num(substr);
			if (num.size()) {
				ret.push_back(num);
			} else {
				ret.clear();
				return ret;
			}
		} else if (subp == "<str>") {
			ret.push_back(substr);
		} else if (subp == "<path>") {
			ret.push_back(str.substr(j));
			return ret;
		} else if (subp != substr) {
			ret.clear();
			return ret;
		}
		i = u + 1, j = v + 1;
	}
	if (i - p.size() != j - str.size()) ret.clear();	// ÅĞ¶ÏÊÇ·ñ½âÎöÈ« 
	return ret;
}

void work(string& str) {
	for (int i = 0; i < n; i++) {
		auto result = match(a[i].p, str);
		if (result.size()) {
			cout << a[i].r;
			for (int j = 1; j < result.size(); j++) {
				cout << " " << result[j];
			}
			cout << endl;
			return;
		}
	}
	puts("404");
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> a[i].p >> a[i].r;
	}
	while (m--) {
		string str;
		cin >> str;
		work(str);
	}
	return 0;
}
