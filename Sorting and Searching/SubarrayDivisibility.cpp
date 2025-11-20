#include <iostream>
#include <vector>
#include <string>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (auto& a : nums) {
        cin >> a;
    }
    vector<int> count(n);
    count[0] = 1;
    ll prefix = 0;
    ll out = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefix += nums[i];
        int modclass = prefix % n;
        if (modclass < 0) modclass += n;
        out += count[modclass];
        count[modclass]++;
    }
    cout << out;
    return 0;
}
