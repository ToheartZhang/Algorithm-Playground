#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    cin >> s;
    int len = s.size();
    int sideSize = (len + 2) / 3;
    int botSize = len - 2*sideSize;
    for (int i = 0; i < sideSize; i++) {
        printf("%c", s[i]);
        if (i != sideSize - 1) {
            for (int i = 0; i < botSize; i++) {
                printf(" ");
            }
        } else {
            for (int i = 0; i < botSize; i++) {
                printf("%c", s[sideSize + i]);
            }
        }
        printf("%c\n", s[len - i - 1]);
    }
    // printf("\n");

    return 0;
}
