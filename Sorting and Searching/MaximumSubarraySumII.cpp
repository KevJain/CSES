#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

template <typename T>
void display(vector<T>& v) {
    for (auto& e : v) cout << e << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n);
    for (auto & num : nums) cin >> num;
    // Compute size a windows
    ll window = 0;
    for (int i = 0; i < a; i++) {
        window += nums[i];
    }
    vector<ll> windows = {window}; // windows[i] = sum(a[i:i+a])
    for (int i = a; i < n; i++) {
        window += nums[i] - nums[i-a];
        windows.emplace_back(window);
    }
    //display(windows);
    ll max_s = 0;
    ll sz = 0;
    vector<ll> max_add(n); // max_add[i] = max subarray beginning at i+1 sz lt b-a
    for (int i = n-1; i >= 0; i--) {
        max_add[i] = max_s;
        max_s += nums[i];
        sz += 1;
        if (sz > b-a) {
            max_s -= nums[i+b-a];
            sz--;
        }
        if (max_s < 0) {
            max_s = 0;
            sz = 0;
        }

    }
    //display(max_add);
    ll mx = -1e18;
    for (int i = 0; i < windows.size(); i++) {
        mx = max(mx, windows[i] + max_add[i+a-1]);
    }
    cout << mx;
    return 0;
}
