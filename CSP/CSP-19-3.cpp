#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 20*1024*1024 + 10;
int w;
char str[MAXN];
vector<string> lines;

bool isBlank(const string& str) {
	for(auto& c : str) {
		if (c != ' ')	return false;
	} 
	return true;
} 

// 0 空行 1 起头项目 2 跟随项目 3 其他 
int getType(const string& str) {
	if (isBlank(str))	return 0;
	if (str.size() >= 2 && str[0] == '*' && str[1] == ' ')	return 1;
	if (str.size() >= 2 && str[0] == ' ' && str[1] == ' ')	return 2;
	return 3;
}

string trim(const string& str) {
	int i = 0, j = str.size() - 1;
	while (i <= j && str[i] == ' ')	i++;
	while (i <= j && str[j] == ' ')	j--;
	if (i > j)	return "";
	return str.substr(i, j - i + 1);
}

int blendLines(const string& str, int width) {
	int ret = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')	continue;
		int j = i + 1;
		while (j < str.size() && j - i + 1 <= width)	j++;
		ret++;
		i = j - 1;
	}
	return max(ret, 1);
}

int main() {
	scanf("%d", &w);
	getchar();
	while (fgets(str, MAXN, stdin)) {
		lines.push_back(str);
		lines.back().pop_back();
	}
	int lst = 0, ans = -1;	// 0 空行 1 段落 2 项目列表 
	for (int i = 0; i < lines.size(); ) {
		int type = getType(lines[i]);
		if (type == 0) {
			i++;
			lst = 0;
		} else if (type == 1) {
			if (lst != 2)	ans++;
			lst = 2;
			string line = trim(lines[i].substr(2));
			i++;
			while (i < lines.size()) {
				if (getType(lines[i]) == 2) {
					line += ' ' + trim(lines[i].substr(2));
					i++;
				} else {
					break;
				}
			}
			ans += blendLines(line, w - 3); 
		} else {
			ans++;
			lst = 1;
			string line = trim(lines[i]);
			i++;
			while (i < lines.size()) {
				int subType = getType(lines[i]); 
				if (subType == 2 || subType == 3) {
					line += ' ' + trim(lines[i]);
					i++;
				} else {
					break;
				}
			}
			ans += blendLines(line, w);
		}
	}
	printf("%d\n", ans);
	return 0;
}
