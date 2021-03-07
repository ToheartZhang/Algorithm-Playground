#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100010;

struct Node {
    vector<int> childs;
} a[MAXN];

int n;
double p, r;
double sum = 0;
double maxPrice = 0;
int ansCnt = 0;

void DFS(int root, double price) {
    if (a[root].childs.size() == 0) {
        if (maxPrice < price) {
            ansCnt = 1;
            maxPrice = price;
        } else if (maxPrice == price) {
            ansCnt++;
        }
        return;
    }
    for (auto& item : a[root].childs) {
        DFS(item, price*r);
    }
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    r = r / 100 + 1;
    int root = 0;
    for (int i = 0; i < n; i++) {
        int father;
        scanf("%d", &father);
        if (father != -1) {
            a[father].childs.push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, p);
    printf("%.2lf %d\n", maxPrice, ansCnt);

    return 0;
}
