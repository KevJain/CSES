#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    char ch;
    int count[26] = {};
    while (cin >> ch) {
        count[ch - 'A']++;
    }
    string middle = "";
    string fwd = "";
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
            if (middle != "") {
                cout << "NO SOLUTION";
                return 0;
            }
            count[i]--;
            middle = string(1, (char)('A' + i));
        }
    }
    for (int i = 0; i < 26; i ++) {
        cout << string(count[i] / 2, (char)('A' + i));
    }
    cout << middle;
    for (int i = 25; i >= 0; i --) {
        cout << string(count[i] / 2, (char)('A' + i));
    }
    return 0;
}
