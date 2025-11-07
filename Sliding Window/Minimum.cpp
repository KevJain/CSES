#include <iostream>
#include <vector>
#include <deque>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    ll x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    ll out = 0;
    deque<pair<int, int>> mins; 
    vector<ll> nums(n);
    for (int i = 0; i < k; i ++) {
        nums[i] = x;
        while (!mins.empty() && mins.back().first >= x) {
            mins.pop_back();
        }
        mins.push_back({x, i});
        x = a * x + b;
        x %= c;
    }
    out = mins.front().first;
    for (int i = k; i < n; i++) {
        nums[i] = x;
        while (!mins.empty() && mins.front().second + k <= i) {
            mins.pop_front();
        }
        while (!mins.empty() && mins.back().first >= x) {
            mins.pop_back();
        }
        mins.push_back({x, i});
        out ^= mins.front().first;
        x = a * x + b;
        x %= c;
    }
    cout << out;
    return 0;
}
