#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int cpy = i;
        while (cpy) {
            dp[i] = min(dp[i], dp[i-(cpy%10)] + 1);
            cpy /= 10;
        }
    }
    cout << dp[n];
    return 0;
}
