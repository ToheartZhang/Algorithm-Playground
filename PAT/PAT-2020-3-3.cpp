#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 1010;
string s;
vector<int> ans;
int n, k, now;
int level[MAXN];
int id[MAXN];
int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int len = s.size();
        for (int j = 0; j < len; j++) {
            if (s[j] == ' ')    level[i] = j + 1;
        }
        id[i] = stoi(s.substr(level[i]));
    }
    scanf("%d", &k);
    while (k--) {
        ans.clear();
        scanf("%d", &now);
        int cur = 0;
        for (; cur < n; cur++) {
            if (now == id[cur])   break;
        }
        if (cur == n) {
            printf("Error: %04d is not found.\n", now);
            continue;
        }
        ans.push_back(now);
        int curLevel = level[cur];
        for (int i = cur - 1; i >= 0; i--) {
            if (curLevel - 1 == level[i]) {
                curLevel = level[i];
                ans.push_back(id[i]);
            }
        }
        printf("0000");
        for (int i = ans.size() - 2; i >= 0; i--) {
            printf("->%04d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}