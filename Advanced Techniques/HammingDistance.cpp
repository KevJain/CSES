#include <iostream>
#include <vector>
#include <string>
#pragma GCC target("popcnt")
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    char ch;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        for (int j = k-1; j >= 0; j--) {
            cin >> ch;
            if (ch == '1') {
                nums[i] |= (1 << j);
            }
        }
    }
    int mn = k;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mn = min(mn, __builtin_popcount(nums[i]^nums[j]));
        }
    }
    cout << mn;
    return 0;
}
