// 1. Count Inversions
// 2. n - # cycles
// 3. n - longest increasing subsequence
// 4. n - (# elements i where i + 1, i + 2, ..., n) are all ordered after i)
#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& num : nums) cin >> num;

    vector<int> tree(n+1);
    auto query = [&tree] (int idx) {
        int s = 0;
        while (idx) {
            s += tree[idx];
            idx -= idx & -idx;
        }
        return s;
    };

    auto update = [&tree] (int idx) {
        while (idx < tree.size()) {
            tree[idx]++;
            idx += idx & -idx;
        }
    };

    ll out1 = 0;
    for (int i = n-1; i >= 0; i--) {
        out1 += query(nums[i]);
        update(nums[i]);
    }

    ll out3 = 0;
    vector<int> seq;
    for (int i = 0; i < n; i++) {
        auto idx = lower_bound(seq.begin(), seq.end(), nums[i]);
        if (idx == seq.end()) {
            seq.push_back(nums[i]);
        } else {
            *idx = nums[i];
        }
    }
    out3 = n - seq.size();
    ll out4 = 0;
    int target = n;
    for (int i = n-1; i >= 0; i--) {
        if (nums[i] == target) target--;
    }
    out4 = target;

    int out2 = 0;

    for (int i = 0; i < n; i++) {
        int original = i;
        int cur = nums[i] - 1;
        while (cur != original) {
            int tmp = nums[cur] - 1;
            nums[cur] = cur + 1;
            cur = tmp;
            out2++;
        }
    }

    cout << out1 << ' ' << out2 << ' ' << out3 << ' ' << out4;

    return 0;
}
