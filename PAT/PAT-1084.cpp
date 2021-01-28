#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

string a, b;
map<char, bool> broken;

int main() {
    cin >> a >> b;
    int lena = a.size();
    int lenb = b.size();
    int cura = 0, curb = 0;
    while (cura < lena) {
        while (cura < lena && curb < lenb && toupper(a[cura]) == toupper(b[curb])) {
            cura++;
            curb++;
        }
        if (broken.find(toupper(a[cura])) == broken.end()) {
            broken[toupper(a[cura])] = true;
            printf("%c", toupper(a[cura]));
        }
        cura++;
    }
    printf("\n");
    return 0;
}
