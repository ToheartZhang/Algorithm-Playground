#include <cstdio>
#include <iostream>
using namespace std;

string a, b, c, d;
int day, hour, minute;

bool isCapital(char c) {
    return c >= 'A' && c <= 'Z';
}

const char WEEK[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    cin >> a >> b >> c >> d;
    int lena = a.size();
    int lenb = b.size();
    int lenc = c.size();
    int lend = d.size();
    int i = 0;
    for (; i < lena && i < lenb; i++) {
        if (a[i] >= 'A' && a[i] <= 'G' && a[i] == b[i]) {
            day = a[i] - 'A';
            i++;
            break;
        }
    }
    for (; i < lena && i < lenb; i++) {
        if (((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i])) && a[i] == b[i]) {
            if (isCapital(a[i])) {
                hour = 10 + a[i] - 'A';
            } else {
                hour = a[i] - '0';
            }
            break;
        }
    }
    i = 0;
    for (; i < lenc && i < lend; i++) {
        if (isalpha(c[i]) && c[i] == d[i]) {
            minute = i;
            break;
        }
    }
    printf("%s ", WEEK[day]);
    printf("%02d:%02d\n", hour, minute);

    return 0;
}
