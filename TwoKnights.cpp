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
    for (int k = 3; k <= n; ++k) {
        total = (k*k) * (k*k - 1) / 2;
        attacks += 2 * min(1, k-3) + 4 * (k - 2) + 4 * (k - );
    }
    return 0;
}
