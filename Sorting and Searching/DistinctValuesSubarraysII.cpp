#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto& a : nums) cin >> a;
    unordered_map<int,int> count;
    int l = 0;
    ll out = 0;
    for (int r = 0; r < n; r++) {
        count[nums[r]]++;
        while (count.size() > k) {
            count[nums[l]]--;
            if (count[nums[l]] == 0) {
                count.erase(nums[l]);
            }
            l++;
        }
        out += r - l + 1;
    }
    cout << out;
    return 0;
}
