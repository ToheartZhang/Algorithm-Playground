/*
 * Description: Just simulating.
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int earlyId, lateId;
vector<string> id;

struct Node {
    int h, m, s;
} earlyNode, lateNode;

bool later(Node& a1, Node& a2) {
    return (a1.h > a2.h) || (a1.h == a2.h && a1.m > a2.m) || (a1.h == a2.h && a1.m == a2.m && a1.s > a2.s);
}

int main() {
    scanf("%d", &n);
    earlyNode.h = 24;
    earlyNode.m = 60;
    earlyNode.s = 60;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        id.push_back(str);
        Node a;
        scanf(" %d:%d:%d", &a.h, &a.m, &a.s);
        if (later(earlyNode, a)) {
            earlyNode = a;
            earlyId = i;
        }
        scanf(" %d:%d:%d", &a.h, &a.m, &a.s);
        if (later(a, lateNode)) {
            lateNode = a;
            lateId = i;
        }
    }
    cout << id[earlyId] << " " << id[lateId] << endl;

    return 0;
}
