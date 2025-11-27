#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<ll> dp(n+1, -1);
    ll mod = 1e9 + 7;
    auto calc = [&](auto self, int x) mutable -> ll {
        if (dp[x] != -1) return dp[x];
        if (x == n) return 1;
        dp[x] = 0;
        for (int neighbour : graph[x]) {
            ll added = self(self, neighbour);
            dp[x] = (dp[x] + added) % mod;
        }
        return dp[x];
    };
    cout << calc(calc, 1);
    return 0;
}
