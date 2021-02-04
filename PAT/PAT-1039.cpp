#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 26*26*26*10 + 1;

vector<int> stu2cls[MAXN];
char nowName[6];
int n, k;

int getID(char* name) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id*26 + (name[i] - 'A');
    }
    id = id*10 + (name[3] - '0');
    return id;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int courseID, ni;
        scanf("%d%d", &courseID, &ni);
        for (int j = 0; j < ni; j++) {
            scanf("%s", nowName);
            int id = getID(nowName);
            stu2cls[id].push_back(courseID);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", nowName);
        printf("%s", nowName);
        int id = getID(nowName);
        sort(stu2cls[id].begin(), stu2cls[id].end());
        printf(" %d", stu2cls[id].size());
        for (auto& item : stu2cls[id]) {
            printf(" %d", item);
        }
        printf("\n");
    }

    return 0;
}
