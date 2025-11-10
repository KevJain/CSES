#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
typedef long long ll;
using namespace std;

vector<ll> twoSum(int start, int target, vector<ll>& nums) {
    int r = nums.size() - 1;
    int l = start;
    if (target < 0) {
        return {};
    }
    while (l < r) {
        int s = nums[l] + nums[r];
        if (s == target) {
            return {nums[l], nums[r]};
        } else if (s > target) {
            r--;
        } else {
            l++;
        }
    }
    return {};
}

vector<ll> nSum(int n, int start, int target, vector<ll>& nums) {
    vector<ll> out;
    if (n == 2) {
        return twoSum(start, target, nums);
    }
    if (target < 0 || n < 2) {
        return {};
    }
    for (int i = start; i + n <= nums.size(); i++) {
        out = nSum(n-1, i+1, target-nums[i], nums);
        if (!out.empty()) {
            out.push_back(nums[i]);
            return out;
        }
    }
    return {};
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<ll> nums(n);
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        pos[nums[i]].push_back(i+1);
    }
    sort(nums.begin(), nums.end());
    vector<ll> choices = nSum(4, 0, target, nums);
    if (choices.empty()) {
        cout << "IMPOSSIBLE";
    } else {
        for (auto a : choices) {
            cout << pos[a].back() << ' ';
            pos[a].pop_back();
        }
    }
    return 0;
}
