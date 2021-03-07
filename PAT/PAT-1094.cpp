#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 110;

struct Node {
    vector<int> childs;
    int level;
} a[MAXN];
queue<Node> q;
int n, m, ans, ansLevel;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int id, num, child;
        scanf("%d%d", &id, &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &child);
            a[id].childs.push_back(child);
        }
    }
    a[1].level = 1;
    q.push(a[1]);
    int preLevel = 0;
    int levelCnt = 0;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (preLevel != now.level) {
            if (ans < levelCnt) {
                ans = levelCnt;
                ansLevel = preLevel;
            }
            preLevel = now.level;
            levelCnt = 0;
        }
        levelCnt++;
        for (auto& item : now.childs) {
            a[item].level = now.level + 1;
            q.push(a[item]);
        }
    }
    if (ans < levelCnt) {
        ans = levelCnt;
        ansLevel = preLevel;
    }
    printf("%d %d\n", ans, ansLevel);

    return 0;
}
