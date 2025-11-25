// Use bitmasks to represent calculator trips already calculated
// Iterate over the masks by number of people placed
// For each mask, store the number of trips used and the total
// weight in the last trip, then for each people not placed in this mask
// we try to place in the final group or create a new group to create a
// candidate mask with one more bit set

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<ll> people(n);
    for (auto& p : people) cin >> p;
    vector<pair<int,ll>> dp(1<<n, {inf, 0}); // number of rides, weight of last ride
    dp[0] = {1,0};
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int j = 0; j < n; j++) { // Try to add j to current mask
            if (mask >> j & 1) continue; // already used
            pair<int,ll> cand = dp[mask];
            if (cand.second + people[j] > x) {
                cand.first++;
                cand.second = people[j];
            } else {
                cand.second += people[j];
            }
            int new_mask = mask | (1<<j);
            dp[new_mask] = min(dp[new_mask], cand);
        }
    }
    cout << dp.back().first;
    return 0;
}
