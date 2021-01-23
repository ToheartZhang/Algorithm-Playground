#include <cstdio>
#include <iostream>

using namespace std;

const int NUM[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D'};

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("#%c%c", NUM[a / 13], NUM[a % 13]);
    printf("%c%c", NUM[b / 13], NUM[b % 13]);
    printf("%c%c\n", NUM[c / 13], NUM[c % 13]);

    return 0;
}
