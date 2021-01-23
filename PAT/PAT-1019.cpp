#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, b;
vector<int> ans;

bool judgePalin() {
    int len = ans.size();
    for (int i = 0; i < len / 2; i++) {
        if (ans[i] != ans[len - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    scanf("%d%d", &n, &b);
    do {
        ans.push_back(n % b);
        n /= b;
    } while(n);
    if (judgePalin()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    int len = ans.size();
    printf("%d", ans[len - 1]);
    for (int i = len - 2; i >= 0; i--) {
        printf(" %d", ans[i]);
    }
    printf("\n");

    return 0;
}