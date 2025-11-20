#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (auto & a: nums) {
        cin >> a;
    }
    auto check = [&](ll lim) -> bool {
        ll cur = 0;
        int divs = 1;
        for (int i = 0; i < n; i++) {
            if (cur + nums[i] > lim) {
                cur = 0;
                divs++;
            }
            cur += nums[i];
        }
        return divs <= k;
    };
    ll lo = *max_element(nums.begin(), nums.end());
    ll hi = accumulate(nums.begin(), nums.end(), 0LL);
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
    return 0;
}
