#include <iostream>
#include <vector>
#include <string>
#include <numeric>
typedef long long ll;
using namespace std;

ll factorial(int m) {
    ll out = 1;
    while (m) {
        out *= m--;
    }
    return out;
}

void find(ll n, ll k) {
    vector<ll> nums(n);
    iota(nums.begin(), nums.end(), 1);
    while (!nums.empty()) {
        ll smaller = factorial(nums.size() - 1);
        int pos = k / smaller;
        cout << nums[pos] << ' ';
        nums.erase(nums.begin() + pos);
        k = k % smaller;
    }
    cout << '\n';
}

void getRank(int n, vector<int>& nums) {
    vector<bool> seen(n+1);
    ll ans = 1;
    for (int i = 0; i < nums.size(); i++) {
        ll smaller = factorial(nums.size() - 1 - i);
        int rank = 0;
        for (int j = 1; j < nums[i]; j++) {
            if (!seen[j]) rank++;
        }
        ans += smaller * rank;
        seen[nums[i]] = true;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int type_;
        cin >> type_;
        if (type_ == 1) {
            ll n, k;
            cin >> n >> k;
            find(n,k-1);
        } else {
            int n;
            cin >> n;
            vector<int> nums(n);
            for (auto& num : nums) {
                cin >> num;
            }
            getRank(n, nums);
        }
    }
    return 0;
}
