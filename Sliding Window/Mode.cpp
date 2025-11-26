#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    auto cmp = [] (pair<int,int> p1, pair<int,int> p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    };
    set<pair<int, int>, decltype(cmp)> window(cmp); // freq, val
    unordered_map<int, int> window_e;
    vector<int> nums(n);
    for (auto & num : nums) cin >> num;
    for (int i = 0; i < k; i++) {
        window_e[nums[i]]++;
    }
    for (auto [num, freq] : window_e) {
        window.insert({freq, num});
    }
    cout << (*window.begin()).second << ' ';
    for (int i = k; i < n; i++) {
        if (nums[i] != nums[i-k]) {
            window.erase({window_e[nums[i-k]], nums[i-k]});
            window_e[nums[i-k]]--;
            if (window_e[nums[i-k]] > 0) {
                window.insert({window_e[nums[i-k]], nums[i-k]});
            }
            if (window_e.count(nums[i])) {
                window.erase({window_e[nums[i]], nums[i]});
            }
            window_e[nums[i]]++;
            window.insert({window_e[nums[i]], nums[i]});
        }
        cout << (*window.begin()).second << ' ';
    }
    return 0;
}
