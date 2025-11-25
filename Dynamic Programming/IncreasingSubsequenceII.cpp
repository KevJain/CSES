// For each number, we can use this number to extend all sequences that end
// with a number smaller than the current number that have already been seen
// Use a Fenwick tree to query previous sequences
// Compress coordinates

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& num : nums) cin >> num;
    vector<int> snums = nums;
    sort(snums.begin(), snums.end());
    auto eu = unique(snums.begin(), snums.end());
    for (int i = 0; i < n; i++) {
        nums[i] = (lower_bound(snums.begin(), eu, nums[i]) - snums.begin()) + 1;
    }
    vector<ll> tree(n+1);

    auto query = [&tree](int idx) {
        ll s = 0;
        while (idx > 0) {
            s += tree[idx];
            s %= mod;
            idx -= (idx & -idx);
        }
        return s;
    };

    auto add = [&tree](int idx, ll diff) {
        while (idx < tree.size()) {
            tree[idx] += diff;
            tree[idx] %= mod;
            idx += (idx & -idx);
        }
    };

    vector<ll> dp(n,1);
    ll out = 0;
    for (int i = 0; i < n; i++) {
        ll added = (query(nums[i]-1) + 1) % mod;
        out += added;
        out %= mod;
        add(nums[i], added);
    }
    cout << out;
    return 0;
}
