#include <iostream>
#include <string>
#include <bitset>
#include <vector>
typedef long long ll;
using namespace std;

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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int sz = n / 64 + 1;
    for (char ch = 'A'; ch < 'A' + k; ch++) {
        vector<vector<ll>> filtered(n, vector<ll>(sz,0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == ch) {
                    filtered[i][j/64] |= ((ll)1) << (j % 64);
                }
        }
            //cout << bitset<64>(filtered[i][0]) <<endl;
        }
        for (int tt = 0; tt < n; tt++) {
            //cout << filtered[tt][0] << endl;
        }
        bool found = false;
        int count = 0;
        for (int r1 = 0; r1 < n-1; r1++) {
            if (found) break;
            for (int r2 = r1 + 1; r2 < n; r2++) {
                count = 0;
                for (int i = 0; i < sz; i++) {
                    count += __builtin_popcount(filtered[r1][i]&filtered[r2][i]);
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
