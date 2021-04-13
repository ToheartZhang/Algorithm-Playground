#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 2020;
int m, n, p, q;
//int rgb = 
const string RESET = "\\x1B\\x5B\\x30\\x6D";
const string TRANS = "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";

struct Color {
	int r = 0, g = 0, b = 0;
	bool operator==(const Color& rhs) const {
		return r == rhs.r && g == rhs.g && b == rhs.b;
	}
} a[MAXN][MAXN];

int getNum(const string& str) {
	int ret = 0;
	if (isdigit(str[0])) {
		ret = (str[0] - '0')*16;
	} else {
		ret = (str[0] - 'a' + 10)*16;
	}
	if (isdigit(str[1])) {
		return ret + (str[1] - '0');
	} else {
		return ret + (str[1] - 'a' + 10);
	}
}

int getSingleNum(const char str) {
	if (isdigit(str)) {
		return str - '0';
	} else {
		return str - 'a' + 10;
	}
}

Color parseColor(const string& str) {
	Color ret;
	if (str.size() == 7) {
		ret.r = getNum(str.substr(1, 2));
		ret.g = getNum(str.substr(3, 2));
		ret.b = getNum(str.substr(5, 2));
	} else if (str.size() == 4) {
		ret.r = getSingleNum(str[1])*16 + getSingleNum(str[1]);
		ret.g = getSingleNum(str[2])*16 + getSingleNum(str[2]);
		ret.b = getSingleNum(str[3])*16 + getSingleNum(str[3]);
	} else {
		ret.r = ret.g = ret.b = getSingleNum(str[1])*16 + getSingleNum(str[1]);
	}
	return ret;
}

void printNum(int num) {
	int temp = num;
	int base = 1;
	while (temp) {
		temp /= 10;
		base *= 10;
	} 
	base /= 10;
	while (base) {
		printf("\\x%02X", num / base + '0');
		num %= base;
		base /= 10;
	}
//	printf("\\x%02X", (char)(num/16));
//	printf("\\x%02X", (char)(num%16));
}

void printColor(const Color& clr) {
	cout << TRANS;
	printNum(clr.r);
	printf("\\x%02X", ';');
	printNum(clr.g);
	printf("\\x%02X", ';');
	printNum(clr.b);
	printf("\\x%02X", 'm');
}

bool isDefault(const Color& clr) {
	return clr.r == 0 && clr.g == 0 && clr.b == 0;
}

int main() {
	scanf("%d%d%d%d", &m, &n, &p, &q);
	int nn = n / q, mm = m / p, size = p*q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string str;
			cin >> str;
			auto res = parseColor(str);
			int ii = i / q, jj = j / p;
//			printf("%x%x%x\n", res.r, res.g, res.b);
			a[ii][jj].r += res.r;
			a[ii][jj].g += res.g;
			a[ii][jj].b += res.b;
//			if (i == 1 && j == 0)
//				printf("%x%x%x\n\n", a[ii][jj].r, a[ii][jj].g, a[ii][jj].b);
		}
	}
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < mm; j++) {
			a[i][j].r /= size;
			a[i][j].g /= size;
			a[i][j].b /= size;
			
			
		}
	}
	Color lastColor;
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < mm; j++) {
			if (!(lastColor == a[i][j])) {
				if (isDefault(a[i][j])) {
					cout << RESET; 
				} else {
					printColor(a[i][j]);	
				}
				lastColor = a[i][j];
				 
			}
//			printf("%x%x%x\n", lastColor.r, lastColor.g, lastColor.b);
			printf("\\x%02X", ' ');
		}
		if (!isDefault(lastColor)) {
			cout << RESET;
			lastColor = {0, 0, 0};
		}
		printf("\\x%02X", '\n');
	}
	return 0;
}
