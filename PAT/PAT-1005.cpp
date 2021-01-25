#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const char NUM_STR[11][7] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int ans = 0;
    char s[110];
    scanf("%s", s);
    int lens = strlen(s);
    for (int i = 0; i < lens; i++) {
        ans += (s[i] - '0');
    }
    vector<int> ansVec;
    do {
        ansVec.push_back(ans % 10);
        ans /= 10;
    } while (ans);
    for (auto iter = ansVec.rbegin(); iter != ansVec.rend(); iter++) {
        if (iter == ansVec.rbegin()) {
            printf("%s", NUM_STR[*iter]);
        } else {
            printf(" %s", NUM_STR[*iter]);
        }
    }
    printf("\n");

    return 0;
}
