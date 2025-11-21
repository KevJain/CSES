#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

vector<ll> check(ll a, vector<ll> nums) {
    vector<ll> out;
    multiset<ll> original(nums.begin(), nums.end());
    out.push_back(a);
    while (original.size() > 0) {
        ll cand = *original.begin() - out[0];
        if (cand < out.back()) return {};
        for (int j = 0; j < out.size(); j++) {
            ll s = out[j] + cand;
            if (original.count(s) == 0) return {};
            original.erase(original.find(s));
        }
        out.push_back(cand);
    }
    return out;
}

void display(vector<ll>& c) {
    for (auto& i : c) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> nums(n * (n-1) / 2);
    for (auto & i : nums) cin >> i;
    sort(nums.begin(), nums.end());
    for (int i = 2; i <= n; i++) {
        // try using nums[i] as b + c
        ll cand = nums[0] + nums[1] - nums[i];
        if (cand % 2 == 0) {
            vector<ll> c = check(cand / 2, nums);
            if (!c.empty()) {
                display(c);
                break;
            }
        }
    }
    return 0;
}
