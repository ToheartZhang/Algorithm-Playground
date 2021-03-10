#include <cstdio>
#include <iostream>
using namespace std;

string a, b;
int ansl, ansr;

int main() {
    cin >> a >> b;
    int lena = ansr = a.size();
    int lenb = b.size();
    for (int i = 0; i < lena; i++) {
        if (a[i] == b[0]) {
            int idx = i + 1, subIdx = 1;
            while (subIdx < lenb && idx < lena && (idx - i) < (ansr - ansl)) {
                if (a[idx] == b[subIdx]) {
                    idx++;
                    subIdx++;
                } else {
                    idx++;
                }
                if (subIdx == lenb) {
                    if (idx - i < ansr - ansl) {
                        ansr = idx;
                        ansl = i;
                    }
                    break;
                }
            }
        }
    }
    for (int i = ansl; i < ansr; i++) {
        printf("%c", a[i]);
    }
    printf("\n");
    return 0;
}