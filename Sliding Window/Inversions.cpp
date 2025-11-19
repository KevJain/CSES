// Coordinate compress the values then use a fenwick tree to count inversions
// Remove element: subtract number of elements less than in window
// Add element: add number of elements greater than in window (inverse of # smaller)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;

void compress(vector<int>& nums) {
    unordered_map<int,int> rank;
    vector<int> cpy = nums;
    sort(cpy.begin(), cpy.end());
    rank[cpy[0]] = 1;
    int crank = 2;
    for (int i = 1; i < nums.size(); i++) {
        if (cpy[i] != cpy[i-1]) {
            rank[cpy[i]] = crank;
            crank++;
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = rank[nums[i]];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto& a : nums) {
        cin >> a;
    }
    compress(nums);

    vector<int> fenwick(n+2);
    auto query = [&](int index) -> int {
        int s = 0;
        while (index) {
            s += fenwick[index];
            index -= index & -index;
        }
        return s;
    };

    auto update = [&](int index, int diff) {
        while (index < fenwick.size()) {
            fenwick[index] += diff;
            index += index & -index;
        }
    };

    ll inversions = 0;
    for (int i = 0; i < k; i++) {
        inversions += i - query(nums[i]);
        update(nums[i], 1);
    }
    cout << inversions << ' ';
    
    for (int i = k; i < n; i++) {
        inversions -= query(nums[i-k] - 1);
        update(nums[i-k], -1);
        inversions += (k-1) - query(nums[i]);
        update(nums[i], 1);
        cout << inversions << ' ';
    }
    return 0;
}
