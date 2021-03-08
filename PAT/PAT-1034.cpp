#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
struct People {
    string name;
    int total;
} a[MAXN];
struct Edge {
    int to;
    int weight;
};
map<string, int> s2i;
vector<Edge> edges[MAXN];
int g[MAXN][MAXN];
map<string, int> ans;
string head;
int blockWt;
int n, k, cnt, block, blockCnt, maxTotal, ansCnt;
bool vis[MAXN];

int regist(string& s) {
    if (s2i.find(s) == s2i.end()) {
        s2i[s] = cnt++;
        a[cnt - 1].name = s;
    }
    return s2i[s];
}

void DFS(int node) {
    vis[node] = true;
    blockCnt++;
    if (maxTotal < a[node].total) {
        maxTotal = a[node].total;
        head = a[node].name;
    }
    for (int i = 0; i < n; i++) {
        if (g[node][i] != 0) {
            blockWt += g[node][i];
            g[node][i] = g[i][node] = 0;
            if (!vis[i]) {
                DFS(i);
            }
        }
    }
}

bool cmp(pair<string, int>& x, pair<string, int>& y) {
    return x.first < y.first;
}

int main() {
    string s1, s2;
    int w;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        scanf("%d", &w);
        int x = regist(s1);
        int y = regist(s2);
        a[x].total += w;
        a[y].total += w;
        g[x][y] += w;
        g[y][x] += w;
    }
    for (int i = 0; i < cnt; i++) {
        if (!vis[i]) {
            maxTotal = 0;
            blockWt = 0;
            blockCnt = 0;
            DFS(i);
            if (blockWt <= k || blockCnt <= 2)
                continue;
            ans[head] = blockCnt;
            ansCnt++;
        }
    }
    printf("%d\n", ansCnt);
    for (auto& p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}