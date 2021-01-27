#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 1010;

int rate[25];
int n;

struct Event {
    string name;
    int month, day, hour, minute;
    bool isOnLine;
    int time;
} a[MAXN];

bool cmp(Event& x, Event& y) {
    if (x.name != y.name) {
        return x.name < y.name;
    } 
    return x.time < y.time;
}

double billFromZero(Event event) {
    double total = rate[event.hour]*event.minute + rate[24]*event.day*60;
    for (int i = 0; i < event.hour; i++) {
        total += rate[i]*60;
    }
    return total / 100.0;
}

int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[10];
        cin >> a[i].name;
        scanf("%d:%d:%d:%d %s", &a[i].month, &a[i].day, &a[i].hour, &a[i].minute, s);
        a[i].isOnLine = (s[1] == 'n');
        a[i].time = 24*60*a[i].day + 60*a[i].hour + a[i].minute;
    }
    sort(a, a + n, cmp);
    map<string, vector<Event>> bill;
    for (int i = 1; i < n; i++) {
        if (a[i].name == a[i - 1].name && !a[i].isOnLine && a[i - 1].isOnLine) {
            bill[a[i].name].push_back(a[i - 1]);
            bill[a[i].name].push_back(a[i]);
        }
    }
    for (auto& item : bill) {
        vector<Event> events = item.second;
        cout << item.first;
        printf(" %02d\n", events[0].month);
        double total = 0.;
        int len = events.size();
        for (int i = 0; i < len; i += 2) {
            printf("%02d:%02d:%02d", events[i].day, events[i].hour, events[i].minute);
            printf(" %02d:%02d:%02d", events[i + 1].day, events[i + 1].hour, events[i + 1].minute);
            int delta = events[i + 1].time - events[i].time;
            double fee = billFromZero(events[i + 1]) - billFromZero(events[i]);
            printf(" %d $%.2lf\n", delta, fee);
            total += fee;
        }
        printf("Total amount: $%.2lf\n", total);
    }

    return 0;
}
