#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
void solve(int a, int b) {
    int n = max(a,b);
    vector<vector<int>> dp(n + 1, vector<int>(n+1, 1e9));
    for (int h = 1; h <= n; h++) {
        for (int w = 1; w <= n; w++) {
            if (h == w) dp[h][w] = 0;
            for (int hcut = 1; hcut <= h/2; hcut++) {
                dp[h][w] = min(dp[hcut][w] + dp[h-hcut][w] + 1, dp[h][w]);
            }
            for (int wcut = 1; wcut <= w/2; wcut++) {
                dp[h][w] = min(dp[h][wcut] + dp[h][w-wcut] + 1, dp[h][w]);
            }
            //cout << h << ',' << w << ' ' << dp[h][w] << endl;
        }
    }
    cout << dp[a][b];
}
int main() {
    int a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}
