#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

ll powmod(ll base, ll exp) {
    ll out = 1;
    while (exp > 0) {
        if (exp & 1) {
            out *= base;
            out %= mod;
        }
        base *= base;
        base %= mod;
        exp >>= 1;
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 2;
    } else {
        cout << ((powmod(2, n * n - 2) + powmod(2, n * n / 2 + (n & 1) - 2) + powmod(2, n * n / 4 + (n & 1) - 1)) % mod);
    }
    return 0;
}
