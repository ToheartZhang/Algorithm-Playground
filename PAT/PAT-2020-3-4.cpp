#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
int n, m, k;
struct Equa {
    vector<int> react;
    int prod;
} a[MAXN];
int reacts[MAXN], prods[MAXN];
int cnt[MAXN];
vector<int> ans;

bool cmp(Equa& p, Equa& q) {
    int lenp = p.react.size();
    int lenq = q.react.size();
    int len = min(lenp, lenq);
    for (int i = 0; i < len; i++) {
        if (p.react[i] != q.react[i]) {
            return p.react[i] < q.react[i];
        }
    }
    return lenp < lenq;
}

void DFS(int now) {
    if (now == m) {
        for (auto& num : ans) {
            printf("%02d", a[num].react[0]);
            for (int l = 1; l < a[num].react.size(); l++) {
                printf(" + %02d", a[num].react[l]);
            }
            printf(" -> %02d\n", a[num].prod);
        }
        exit(0);
    }
    for (int j = 0; j < k; j++) {
        if (a[j].prod != prods[now])  continue;
        bool succ = true;
        for (auto& r : a[j].react) {
            if (!cnt[r]) {
                succ = false;
                break;
            }
        }
        if (!succ)  continue;
        for (int l = 0; l < a[j].react.size(); l++) {
            cnt[a[j].react[l]]--;
        }
        ans.push_back(j);
        DFS(now + 1);
        ans.pop_back();
        for (int l = 0; l < a[j].react.size(); l++) {
            cnt[a[j].react[l]]++;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &reacts[i]);
        cnt[reacts[i]]++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &prods[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int r;
        scanf("%d", &r);
        a[i].react.push_back(r);
        while (true) {
            char c;
            while ((c = getchar()) == ' ');
            if (c == '+') {
                scanf("%d", &r);
                a[i].react.push_back(r);
            } else if (c == '-') {
                getchar();
                break;
            }
        }
        scanf("%d", &a[i].prod);
    }
    for (int i = 0; i < m; i++) {
        if (cnt[prods[i]]) {
            a[k].react.push_back(prods[i]);
            a[k++].prod = prods[i];
        }
    }
    sort(a, a + k, cmp);
    DFS(0);
    return 0;
}