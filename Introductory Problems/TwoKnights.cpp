#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll total;
    ll attacks = 0;
    cout << 0 << '\n';
    if (n >= 2) {
        cout << 6 << '\n';
    }
    for (ll k = 3; k <= n; ++k) {
        total = (k*k) * (k*k - 1) / 2;
        attacks += (8 * k - 16);
        cout << (total - attacks) << '\n';
    }
    return 0;
}
