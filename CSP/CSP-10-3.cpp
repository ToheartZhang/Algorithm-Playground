#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<string> strs;

int workLink(const string&, int);

int workEm(const string& str, int idx) {
	printf("<em>");
	int j = idx + 1;
	while (j < str.size() && str[j] != '_') {
		if (str[j] == '[') j = workLink(str, j);
		else	printf("%c", str[j]);
		j++;
	}
	printf("</em>");
	return j;
}

int workLink(const string& str, int idx) {
	string text, link;
	int j = idx + 1;
	while (j < str.size() && str[j] != ']') {
		if (str[j] == '_') {
			text += "<em>";
			j++;
			while (str[j] != '_')	text += str[j++];
			text += "</em>";
		} else {
			text += str[j];
		}
		j++;
	}
	j += 2;
	while (j < str.size() && str[j] != ')') {
		link += str[j];
		j++;
	}
    printf("<a href=\"%s\">%s</a>", link.c_str(), text.c_str());
    return j;
}

void workLine(string str) {
	int k = 0;
	while (str[k] == ' ')	k++;
	str = str.substr(k);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '_') {
			i = workEm(str, i);
		} else if (str[i] == '[') {
			i = workLink(str, i);
		} else {
			printf("%c", str[i]);
		}
	}
}

void work(int l, int r) {
	if (strs[l][0] == '#') {
		int j = 0;
		while (j < strs[l].size() && strs[l][j] == '#')	j++;
		printf("<h%d>", j);
		workLine(strs[l].substr(j));
		printf("</h%d>\n", j);
	} else if (strs[l][0] == '*') {
		printf("<ul>\n");
		for (int i = l; i <= r; i++) {
			printf("<li>");
			workLine(strs[i].substr(1));
			printf("</li>\n");
		}
		printf("</ul>\n");
	} else {
		printf("<p>");
		for (int i = l; i <= r; i++) {
			workLine(strs[i]);
			if (i != r)	printf("\n");
		}
		printf("</p>\n");
	}
}

int main() {
	string str;
	while (getline(cin, str)) {
		strs.push_back(str);
	}
	for (int i = 0; i < strs.size(); i++) {
		if (strs[i].empty())	continue;
		int j = i + 1;
		while (j < strs.size() && !strs[j].empty())	j++;
		work(i, j - 1);
		i = j - 1;
	}
}
