#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;

unordered_map<string, int> dfs(const string& str, int& k) {
	unordered_map<string, int> ret;
	while (k < str.size()) {
		if (str[k] == '(') {
			k++;
			auto t = dfs(str, k);
			k++;
			int a = 1, l = k;
			while (l < str.size() && isdigit(str[l]))	l++;
			if (l > k) {
				a = stoi(str.substr(k, l - k));
				k = l;
			}
			for (auto& c : t) {
				ret[c.first] += c.second*a;
			}
		} else if (str[k] == ')') {
			break;			
		} else {
			int l = k + 1;
			while (l < str.size() && str[l] >= 'a' && str[l] <= 'z')	l++;
			auto key = str.substr(k, l - k);
			k = l;
			int a = 1;
			while (l < str.size() && isdigit(str[l]))	l++;
			if (l > k) {
				a = stoi(str.substr(k, l - k));
				k = l;
			}
			ret[key] += a;
		}
	}
	return ret;
}

unordered_map<string, int> work(const string& str) {
	unordered_map<string, int> res;
	for (int i = 0; i < str.size(); i++) {
		int j = i + 1;
		while (j < str.size() && str[j] != '+')	j++;
		auto item = str.substr(i, j - i);
		i = j;
		int k = 0, a = 1;
		while (k < item.size() && isdigit(item[k]))	k++;
		if (k)	a = stoi(item.substr(0, k));
		auto t = dfs(item, k);
		for (auto& c : t) {
			res[c.first] += c.second*a;
		}
	}
	return res;
}

int main() {
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		int k = str.find("=");
		auto left = str.substr(0, k), right = str.substr(k + 1);
		if (left == right)	puts("Y");
		else {
			auto leftMap = work(left);
			auto rightMap = work(right);
			if (leftMap == rightMap)	puts("Y");
			else	puts("N");
		}
	}
}
