#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

const int MAXN = 33;

int n, in[MAXN], post[MAXN];
bool isFirst = true;
map<int, int> level;

/*
         4
     1      6
       3  5   7
     2
*/

void traverse(int postRoot, int inL, int inR, int index) {
    if (inL >= inR) {
        return;
    }
    int root = post[postRoot];
    int inRoot = inL;
    for (int i = inL; i < inR; i++) {
        if (in[i] == root) {
            inRoot = i;
            break;
        }
    }
    level[index] = root;
    traverse(postRoot - (inR - inRoot), inL, inRoot, 2*index + 1);
    traverse(postRoot - 1, inRoot + 1, inR, 2*index + 2);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    traverse(n - 1, 0, n, 0);
    auto it = level.begin();
    printf("%d", (it++)->second);
    while (it != level.end()) {
        printf(" %d", it->second);
        it++;
    }
    printf("\n");

    return 0;
}
