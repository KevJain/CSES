#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    map<ll, int> count = {{0,1}};
    ll prefix = 0;
    ll out = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefix += nums[i];
        out += count[prefix - target];
        count[prefix]++;
    }
    cout << out;
    return 0;
}
