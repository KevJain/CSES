#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> vals(n);
    vector<ll> prefix = {0};
    for (auto & v : vals) {
        cin >> v;
        prefix.push_back(prefix.back() + v);
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; i ++) {
        dp[i][i] = vals[i];
    }
    for (int l = n-1; l >= 0 ; l--) {
        for (int r = l + 1; r < n; r++) {
            ll s = prefix[r+1] - prefix[l];
            dp[l][r] = max(s - dp[l+1][r], s - dp[l][r-1]);
        }
    }
    cout << dp[0][n-1];
    return 0;
}
