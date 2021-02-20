#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> powTable, ans, tempAns;
int n, k, p, maxFacSum;

void DFS(int index, int nowK, int nowSum, int nowFacSum) {
    if (nowK == k) {
        if (nowSum == n && nowFacSum > maxFacSum) {
            maxFacSum = nowFacSum;
            ans = tempAns;
        }
        return;
    }
    for (int i = index - 1; i >= 1; i--) {
        int tempSum = nowSum + powTable[i];
        if (tempSum <= n) {
            tempAns[nowK] = i;
            DFS(i + 1, nowK + 1, tempSum, nowFacSum + i);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    int now = 0, base = 0;
    while (now <= n) {
        powTable.push_back(now = (int)pow(base, p));
        base++;
    }
    tempAns.resize(k);
    DFS(powTable.size(), 0, 0, 0);
    if (ans.size() == 0) {
        printf("Impossible\n");
        return 0;
    }
    int ansLen = ans.size();
    printf("%d = ", n);
    for (int i = 0; i < ansLen; i++) {
        if (i != 0) {
            printf(" + ");
        }
        printf("%d^%d", ans[i], p);
    }
    printf("\n");

    return 0;
}
