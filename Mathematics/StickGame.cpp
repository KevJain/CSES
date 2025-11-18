#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sticks(k);
    for (auto &s: sticks) {
        cin >> s;
    }
    vector<bool> win(n+1);
    for (int i = 1; i <= n; i++) {
        bool canWin = false;
        for (auto s : sticks) {
            if (s > i) continue;
            if (!win[i-s]) {
                canWin = true;
                break;
            }
        }
        if (canWin) {
            win[i] = true;
            cout << 'W';
        } else {
            cout << 'L';
        }
    }

    return 0;
}
