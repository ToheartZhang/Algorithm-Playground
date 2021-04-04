#include <cstdio>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int n;
stack<int> stk;
stack<char> symbols;

int calculate(int a, int b, char s) {
	if (s == '+')	return a + b;
	if (s == '-')	return a - b;
	if (s == 'x')	return a * b;
	if (s == '/') {
		if (a*b >= 0)	return a / b;
		else if (a % b == 0){
			return a / b;
		} else {
			return a / b - 1;
		}
	}
	exit(0);
}

void eval() {
	char s = symbols.top();	symbols.pop();
	int a = stk.top(); stk.pop();
	int b = stk.top(); stk.pop();
	int result = calculate(b, a, s);
	stk.push(result);
}

int main() {
	unordered_map<char, int> mp;
	mp['+'] = mp['-'] = 0;
	mp['x'] = mp['/'] = 1;
	scanf("%d", &n);
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (isdigit(str[j]))	stk.push(str[j] - '0');
			else {
				while(!symbols.empty() && mp[symbols.top()] >= mp[str[j]]) {
					eval();
				}
				symbols.push(str[j]);
			}
		}
		while (!symbols.empty()) {
			eval();
		}
		if (stk.top() == 24) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		while(!symbols.empty())	symbols.pop();
		while(!stk.empty())	stk.pop();
	}
	return 0;
}
