#include <iostream>
#include <string>
#include <bitset>
#include <vector>
typedef long long ll;
using namespace std;

#pragma GCC target("popcnt")

void print_(vector<char>& v) {
    for (auto c : v) {
        cout << c;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<char>> grid(n,vector<char>(n));
    int sz = n / 64 + 1;
    vector<vector<vector<ll>>> filtered(k, vector<vector<ll>>(n, vector<ll>(sz,0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            filtered[ch-'A'][i][j/64] |= 1LL << (j % 64);
        }
    }

    for (int ch = 0; ch < k; ch++) {
        bool found = false;
        int count = 0;
        for (int r1 = 0; r1 < n-1; r1++) {
            if (found) break;
            for (int r2 = r1 + 1; r2 < n; r2++) {
                count = 0;
                for (int i = 0; i < sz; i++) {
                    count += __builtin_popcount(filtered[ch][r1][i]&filtered[ch][r2][i]);
                }
                if (count > 1) {
                    found = true;
                    break;
                }
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}
