#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const int MAXN = 110;
int n, m;
struct Rule {
	vector<string> p; 
	string r;
	bool isEnd;
} rules[MAXN];

vector<string> work(const string& str) {
	vector<string> items;
	for (int i = 1; i < str.size(); i++) {
		int j = i + 1;
		while (j < str.size() && str[j] != '/')	j++;
//		if (j < str.size())
//			items.push_back(str.substr(i, j - i + 1));
//		else
		items.push_back(str.substr(i, j - i));
		i = j;
	}
	return items;
}

string getNum(const string& str) {
	string ret;
	for (auto& c : str) {
		if (isdigit(c))	ret += c;
		else {
			ret.clear();
			return ret;
		}
	}
	int i = 0;
	while (i + 1 < str.size() && str[i] == '0')	i++;
	return ret.substr(i);
}

vector<string> check(const vector<string>& items, const vector<string>& p, bool isPEnd, bool isIEnd) {
	vector<string> ret(1);
	int i = 0;
	for (i = 0; i < p.size() && i < items.size(); i++) {
		if (p[i] == "<str>") {
			ret.push_back(items[i]);
		} else if (p[i] == "<int>") {
			auto num = getNum(items[i]);
			if (!num.empty()) {
				ret.push_back(num);
			} else {
				ret.clear();
				return ret;
			}
		} else if (p[i] == "<path>") {
			string temp;
			for (int j = i; j < items.size(); j++) {
				temp += items[j];
				if (j != items.size() - 1 || isIEnd)	temp += "/";
			}
			ret.push_back(temp);
			return ret;
		} else if (items[i] != p[i]) {
			ret.clear();
			return ret;
		}
	}
	if (p.size() != items.size() || isPEnd != isIEnd) {
		ret.clear();	
		return ret;
	}
	return ret;
}

void query(const string& str) {
	bool isEnd = str.back() == '/';
	auto queryItems = work(str);
	for (int i = 0; i < n; i++) {
		auto res = check(queryItems, rules[i].p, rules[i].isEnd, isEnd);
		if (!res.empty()) {
			cout << rules[i].r;
			for (int j = 1; j < res.size(); j++) {
				cout << " " << res[j];
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
		string str;
		cin >> str >> rules[i].r;
		rules[i].isEnd = str.back() == '/';
		rules[i].p = work(str);
//		for (auto& item : rules[i].p) {
//			cout << item << " ";
//		}
//		cout << endl;
	}
	while(m--) {
		string str;
		cin >> str;
		query(str);
	}
	return 0;
}
