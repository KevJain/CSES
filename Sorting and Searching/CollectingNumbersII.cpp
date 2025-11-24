#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> loc(n+2, -1); // loc[x] = location of x in nums
    vector<int> nums(n+2);
    vector<int> contr(n+2);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        loc[nums[i]] = i;
        if (loc[nums[i]-1] == -1) {
            count++;
            contr[nums[i]]++;
        }
    }

    auto update = [&](int val) {
        int out = 0;
        int d = 0;
        if (val > 1) {
            d = loc[val] > loc[val-1] ? 0 : 1;
            out += d - contr[val];
            contr[val] = d;
        }
        if (val < n) {
            d = loc[val+1] > loc[val] ? 0 : 1;
            out += d - contr[val+1];
            contr[val+1] = d;
        }
        return out;
    };
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        loc[nums[a]] = b;
        loc[nums[b]] = a;
        swap(nums[a], nums[b]);        
        count += update(nums[a]);
        count += update(nums[b]);
        cout << count << '\n';
    }
    return 0;
}
