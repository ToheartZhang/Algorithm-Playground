#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    a += b;
    if (a < 0) {
        printf("-");
        a = -a;
    }
    do {
        ans.push_back(a % 10);
        a /= 10;
    } while (a);
    int len = ans.size();
    int mod = len % 3;

    for (int i = len - 1; i >= len - mod; i--) {
        printf("%d", ans[i]);
    }
    if (mod != len && mod)
        printf(",");
    for (int i = len - mod - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i && i % 3 == 0) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
