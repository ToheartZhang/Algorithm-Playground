#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

map<string, int> hashTable;
string input;
string ansWord;
int ansCnt;

int main() {
    getline(cin, input);
    int pos = 0;
    int len = input.size();
    while (pos < len) {
        while (pos < len && !isalnum(input[pos])) {
            pos++;
        }
        if (pos >= len) {
            break;
        }
        string word = "";
        while (pos < len && isalnum(input[pos])) {
            word += tolower(input[pos]);
            pos++;
        }
        hashTable[word]++;
    }

    for (auto& item : hashTable) {
        if (ansCnt < item.second) {
            ansWord = item.first;
            ansCnt = item.second;
        }
    }
    cout << ansWord << " " << ansCnt << endl;

    return 0;
}
