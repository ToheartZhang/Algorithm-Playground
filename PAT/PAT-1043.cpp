#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1010;

int n;
int pre[MAXN];
bool isMirror = true;
vector<int> post;

void getPost(int l, int r) {
    if (r - l < 1) {
        return;
    }
    int i = l + 1, j = r - 1;
    if (!isMirror) {
        while (i < r && pre[i] < pre[l])    i++;
        while (j > l && pre[j] >= pre[l])  j--;
    } else {
        while (i < r && pre[i] >= pre[l])   i++;
        while (j > l && pre[j] < pre[l])   j--;
    }
    if (i - j != 1) {
        return;
    }
    getPost(l + 1, i);
    getPost(i, r);
    post.push_back(pre[l]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    getPost(0, n);
    if (post.size() != n) {
        isMirror = false;
        post.clear();
        getPost(0, n);
    }
    if (post.size() == n) {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", post[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
