#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    int total = n * (n + 1) / 2;
    if (total % 2 == 1) {
        cout << 0;
        return 0;
    }
    int target = total / 2;
    vector<ll> dp(target + 1); // dp[i] = ways to make i
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
    cout << ((dp[target] * 500000004) % mod);
    return 0;
}
