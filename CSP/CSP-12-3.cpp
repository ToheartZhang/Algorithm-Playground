#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

const int MONTH_DAY[] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
const string KEYS[] = {
	"jan", "feb", "mar", "apr", "may", "jun",
    "jul", "aug", "sep", "oct", "nov", "dec",
    "sun", "mon", "tue", "wed", "thu", "fri",
    "sat"
};
int n;
string s, t;
unordered_map<string, int> str2num;
struct Time {
	int year, minu, hour, mDay, month, wDay;
	Time(const string& str) {
		sscanf(str.c_str(), "%04d%02d%02d%02d%02d", &year, &month, &mDay, &hour, &minu);
	}
	bool isLeap() {
		return (year % 4 == 0 && year % 100) || year% 400 == 0;
	}
	int getMonthDay() {
		if (month == 2)	return MONTH_DAY[2] + isLeap();
		return MONTH_DAY[month];
	}
	void next() {
		if (++minu == 60) {
			minu = 0;
			if (++hour == 24) {
				hour = 0;
				wDay = (wDay + 1) % 7;
				if (++mDay > getMonthDay()) {
					mDay = 1;
					if (++month > 12) {
						month = 1;
						year++;
					}
				}
			} 
		}
	}
	void printTime() {
		printf("%04d%02d%02d%02d%02d", year, month, mDay, hour, minu);
	}
	bool operator<(const Time& rhs) const {
		if (year != rhs.year)	return year < rhs.year;
		if (month != rhs.month)	return month < rhs.month;
		if (mDay != rhs.mDay)	return mDay < rhs.mDay;
		if (hour != rhs.hour)	return hour < rhs.hour;
		return minu < rhs.minu;
	}
};
struct Task {
	bool minu[60], hour[24], mDay[32], month[13], wDay[7];
	string cmd;
	bool check(Time& t) {
		return minu[t.minu] && hour[t.hour] && mDay[t.mDay] 
				&& month[t.month] && wDay[t.wDay];
	}
} tasks[22];

void init() {
	for (int i = 0; i < 12; i++) {
		str2num[KEYS[i]] = i + 1;
	}
	for (int i = 0; i < 7; i++) {
		str2num[KEYS[i + 12]] = i;
	}
}

int parseNum(const string &s) {
	if (isdigit(s[0]))	return stoi(s);
	string ret;
	for (auto& c : s)	ret += tolower(c);
	return str2num[ret];
}

void work (const string& str, bool st[], int up) {
	if (str == "*") {
		for (int i = 0; i < up; i++)	st[i] = true;
	} else {
		for (int i = 0; i < str.size(); i++) {
			int j = i + 1;
			while (j < str.size() && str[j] != ',')	j++;
			string temp = str.substr(i, j - i);
			i = j;
			int k = temp.find('-');
			if (k == string::npos) {
				st[parseNum(temp)] = true;
			} else {
				int start = parseNum(temp.substr(0, k)), end = parseNum(temp.substr(k + 1));
				for (int k = start; k <= end; k++)	st[k] = true;
			}
		}
	}
}

int main() {
	init();
	scanf("%d", &n);
	cin >> s >> t;
	for (int i = 0; i < n; i++) {
		string minu, hour, mDay, month, wDay;
		cin >> minu >> hour >> mDay >> month >> wDay;
		work(minu, tasks[i].minu, 60);
		work(hour, tasks[i].hour, 24);
		work(mDay, tasks[i].mDay, 32);
		work(month, tasks[i].month, 13);
		work(wDay, tasks[i].wDay, 7);
		cin >> tasks[i].cmd;
	}
	Time base("197001010000"), left(s), right(t);
	base.wDay = 4;
	while (base < right) {
		if (!(base < left)) {
			for (int i = 0; i < n; i++) {
				if (tasks[i].check(base)) {
					base.printTime();
					cout << " " << tasks[i].cmd << endl;
				}
			}
		}
		base.next();
	}
	return 0;
}
