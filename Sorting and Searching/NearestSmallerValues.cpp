#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &a : nums) {
        cin >> a;
    }
    vector<int> out(n);
    vector<pair<int,int>> prevs; // Monotonic increasing stack (element, index)
    for (int i = 0; i < n; i ++) {
        while (!prevs.empty() && prevs.back().first >= nums[i]) {
            prevs.pop_back();
        }
        if (prevs.empty()) {
            out[i] = 0;
        } else {
            out[i] = prevs.back().second;
        }
        prevs.push_back({nums[i], i+1});
    }
    for (auto x : out) {
        cout << x << ' ';
    }
    return 0;
}
