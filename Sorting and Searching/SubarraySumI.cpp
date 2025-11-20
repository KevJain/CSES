#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    ll target;
    cin >> n >> target;
    vector<ll> nums(n);
    for (auto& a : nums) {
        cin >> a;
    }
    ll r = 0;
    ll window = nums[0];
    int count = 0;
    for (int l = 0; l < n; l++) {
        while (r + 1 < n && window < target) {
            window += nums[++r];
        }
        if (window == target) count++;
        window -= nums[l];
    }
    cout << count;
    return 0;
}
