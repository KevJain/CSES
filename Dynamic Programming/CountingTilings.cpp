#include <iostream>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    if ((n * m) % 2 == 1) {
        cout << 0;
        return 0;
    } else if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<ll> dp(1<<n);
    vector<vector<int>> transitions(1<<n, vector<int>());
    for (int mask = (1<<n) - 1; mask >= 0; mask--) {
        set<int> dests;
        dests.insert((mask) ^ ((1<<n)-1));
        for (int b = 0; b < n-1; b++) {
            if (((mask >> b) & 3) == 0) {
                int sub_mask = mask | (3 << b);
                for (int fmask : transitions[sub_mask]) {
                    dests.insert(fmask);
                }
            }
        }
        for (auto it : dests) {
            transitions[mask].push_back(it);
        }
    }
    dp[0] = 1;
    ll mod = 1e9+7;
    vector<ll> temp(1<<n);
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < 1<<n; mask++) {
            for (auto nmask : transitions[mask]) {
                temp[nmask] += dp[mask];
                temp[nmask] %= mod;
            }
        }
        swap(dp, temp);
        temp.assign((1<<n), 0);
    }
    cout << dp[0];
    return 0;
}
