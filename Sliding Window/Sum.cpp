#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    ll x, a, b, c;
    int mod = 1e9 + 7;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    ll out = 0;
    ll window = 0;
    vector<ll> nums(n);
    for (int i = 0; i < k; i ++) {
        nums[i] = x;
        window += x;
        x = a * x + b;
        x %= c;
    }
    out = window;
    for (int i = k; i < n; i++) {
        nums[i] = x;
        window += x;
        window -= nums[i-k];
        out ^= window;
        x = a * x + b;
        x %= c;
    }
    cout << out;
    return 0;
}
