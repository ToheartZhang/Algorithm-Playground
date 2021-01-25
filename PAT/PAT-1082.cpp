#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const char NUM_STR[11][7] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const char LOC_STR[11][7] = {"Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
char s[11];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    int start = 0;
    if (s[0] == '-') {
        printf("Fu ");
        start = 1;
    }
    int lst = 0;
    int i = start;
    while (i < len) {
        if (i == start) {
            printf("%s", NUM_STR[s[i] - '0']);
            if (i != len - 1)
                printf(" %s", LOC_STR[len - i - 2]);
            i++;
            continue;
        }
        if (s[i] - '0' == 0) {
            int tempStart = i;
            while (s[i] - '0' == 0 && i < len) {
                if (len - i - 2 == 3 && len - tempStart - 2 < 6) {
                    printf(" Wan");
                }
                i++;
            }
            if (i != len && len - i - 2 != 2) {
                printf(" ling");
            } else if (i == len) {
                break;
            }
        }
        else {
            printf(" %s", NUM_STR[s[i] - '0']);
            if (i != len - 1)
                printf(" %s", LOC_STR[len - i - 2]);
            i++;
        }
        
    }
    printf("\n");

    return 0;
}
