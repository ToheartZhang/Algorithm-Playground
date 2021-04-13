	#include <cstdio>
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <vector>
	#include <stack>
	#include <set>
	using namespace std;
	
	const int MAXN = 110;
	int n, m;
	struct Row{
		string name;
		string id = "";
		int level;
	} a[MAXN];
	set<int> res;
	int nowIdx;
	
	bool check(const string& sel, const Row& row) {
		if (sel[0] == '#')	return row.id == sel;
		return row.name == sel;
	}
	
	void recur(const vector<string>& sels, int idx, int cur, int lastLevel) {
		if (idx == sels.size()) {
			res.insert(cur);
			return;
		}
		for (int i = cur; i < n; i++) {
			if (a[i].level == lastLevel)	break;
			if (check(sels[idx], a[i]) && lastLevel < a[i].level) {
				recur(sels, idx + 1, i + 1, a[i].level);
			}
		}
	}
	
	void work(vector<string>& sels) {
		res.clear();
		recur(sels, 0, 0, -1);
		cout << res.size();
		for (auto& item : res) {
			cout << " " << item;
		}
		cout << endl;
	}
	
	int main() {
		scanf("%d%d", &n, &m);
		getchar();
		for (int i = 0; i < n; i++) {
			string str;
			getline(cin, str);
			int pos = 0;
			for (int j = 0; j < str.size(); j++) {
				if (str[j] == '.') {
					pos = j + 1;
					a[i].level = (j + 1) / 2;
					continue;
				}
				if (str[j] == ' ') {
					a[i].name = str.substr(pos, j - pos);
					for (auto& c : a[i].name) {
						c = tolower(c);
					}
					a[i].id = str.substr(j + 1);
					break;
				}
			}
			if (!a[i].name.size()) {
				a[i].name = str.substr(pos);
				for (auto& c : a[i].name) {
					c = tolower(c);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			string str;
			getline(cin, str);
			stringstream sstr(str);
			string selector;
			vector<string> sels;
			while (sstr >> selector) {
				if (selector[0] != '#') {
					for (auto& c : selector) {
						c = tolower(c);
					}
				}
				sels.push_back(selector);
			}
			work(sels);
		}
	}
