/*
 * Description: Just simulating.
 */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 15;
const int INF = 0x3f3f3f3f;

struct Stu {
    char name[15];
    char course[15];
    int grade;
};

int n;
bool hasBoy, hasGirl;
int lowBoy = -1, highGirl = -1;
int lowBoyGrade = INF, highGirlGrade;
vector<Stu> stus;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Stu stu;
        char c;
        scanf("%s %c %s%d", stu.name, &c, stu.course, &stu.grade);
        stus.push_back(stu);
        if (c == 'M') {
            if (lowBoyGrade > stu.grade) {
                lowBoyGrade = stu.grade;
                lowBoy = i;
            }
        } else {
            if (highGirlGrade < stu.grade) {
                highGirlGrade = stu.grade;
                highGirl = i;
            }
        }
    }

    if (highGirl != -1) {
        printf("%s %s\n", stus[highGirl].name, stus[highGirl].course);
    } else {
        printf("Absent\n");
    }

    if (lowBoy != -1) {
        printf("%s %s\n", stus[lowBoy].name, stus[lowBoy].course);
    } else {
        printf("Absent\n");
    }


    if (highGirl != -1 && lowBoy != -1) {
        printf("%d\n", stus[highGirl].grade - stus[lowBoy].grade);
    } else {
        printf("NA\n");
    }

    return 0;
}
