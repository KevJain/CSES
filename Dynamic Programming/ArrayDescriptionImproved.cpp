#include <iostream>
#include <vector>
#include <string>
#include <numeric>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> nums(n);
    for (auto& a : nums) {
        cin >> a;
    }
    ll mod = 1e9 + 7;
    ll ways[102] = {}; //ways[i] = # ways to have i at current pos
    if (nums[0] == 0) {
        for (int i = 1; i <= m; i ++) ways[i] = 1;
    } else {
        ways[nums[0]] = 1;
    }
    ll prev;
    for (int i = 1; i < n; i ++) {
        if (nums[i] != 0) {
            ways[nums[i]] = (ways[nums[i]-1] + ways[nums[i]] + ways[nums[i]+1]) % mod;
            for (int j = 1; j <= m; j++) {
                if (j == nums[i]) continue;
                ways[j] = 0;
            }
        } else {
            prev = 0;
            for (int j = 1; j <= m; j++) {
                ll temp = ways[j];
                ways[j] += prev + ways[j+1];
                ways[j] %= mod;
                prev = temp;
            }
        }
    }
    if (nums[n-1] == 0) {
        ll out = 0;
        for (int j = 1; j <= m; j++) {
            out += ways[j];
            out %= mod;
        }
        cout << out;
    } else {
        cout << ways[nums[n-1]];
    }
    return 0;
}
