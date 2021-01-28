#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

const int MAXN = 10100;

struct Action {
    char plate[9];
    int hour, minute, second;
    int time;
    bool isIn;
} all[MAXN], valid[MAXN];

bool cmp(Action& x, Action& y) {
    if (strcmp(x.plate, y.plate)) {
        return strcmp(x.plate, y.plate) < 0;
    }
    return x.time < y.time;
}

bool cmp1(Action& x, Action& y) {
    return x.time < y.time;
}

int n, k, maxTime;
map<string, int> parkTime;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        char temp[4];
        scanf("%s %d:%d:%d %s", all[i].plate, &all[i].hour, &all[i].minute, &all[i].second, temp);
        if (temp[0] == 'i') {
            all[i].isIn = true;
        }
        all[i].time = all[i].hour*60*60 + all[i].minute*60 + all[i].second;
    }
    sort(all, all + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(all[i].plate, all[i+1].plate) == 0 && all[i].isIn && !all[i+1].isIn) {
            valid[cnt++] = all[i];
            valid[cnt++] = all[i+1];
            int delta = all[i+1].time - all[i].time;
            if (parkTime.find(all[i].plate) == parkTime.end()) {
                parkTime[all[i].plate] = 0;
            }
            parkTime[all[i].plate] += delta;
            maxTime = max(maxTime, parkTime[all[i].plate]);
        }
    }
    sort(valid, valid + cnt, cmp1);
    int now = 0;
    int parkCnt = 0;
    for (int i = 0; i < k; i++) {
        int hour, minute, second;
        scanf("%d:%d:%d", &hour, &minute, &second);
        int time = hour*60*60 + minute*60 + second;
        while (valid[now].time <= time && now < cnt) {
            if (valid[now].isIn) {
                parkCnt++;
            } else {
                parkCnt--;
            }
            now++;
        }
        printf("%d\n", parkCnt);
    }
    for (auto& item : parkTime) {
        if (item.second == maxTime) {
            cout << item.first << " ";
        }
    }
    printf("%02d:%02d:%02d\n", maxTime / 3600, (maxTime % 3600) / 60, maxTime % 60);

    return 0;
}
