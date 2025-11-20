#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int LIMIT = 200000;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto & a: nums) {
        cin >> a;
    }
    set<int> missing;
    unordered_map<int, int> remove; // index to remove
    for (int i = 0; i <= k; i++) missing.insert(i);
    for (int i = 0; i < k; i++) {
        missing.erase(nums[i]);
        remove[nums[i]] = i + k;
    }
    cout << *missing.begin() << ' ';
    for (int i = k; i < n; i++) {
        if (remove[nums[i-k]] == i) {
            missing.insert(nums[i-k]);
        }
        remove[nums[i]] = i + k;
        missing.erase(nums[i]);
        cout << *missing.begin() << ' ';
    }
    return 0;
}
