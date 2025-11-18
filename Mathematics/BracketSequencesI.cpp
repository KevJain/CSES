#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;
const int LIMIT = 1e6;

ll fact[LIMIT+1] = {};
ll ifact[LIMIT+1] = {};

ll powmod(ll base, ll exp) {
    ll out = 1;
    while (exp) {
        if (exp & 1) {
            out = (out*base)%mod;
        }
        base = (base*base)%mod;
        exp >>= 1;
    }
    return out;
}

ll modinv(ll num) {
    return powmod(num, mod-2);
}

void compute_factorial() {
    fact[0] = 1;
    for (int i = 1; i <= LIMIT; i++) {
        fact[i] = (i*fact[i-1])%mod;
    }
}

void compute_ifact() {
    ifact[LIMIT] = modinv(fact[LIMIT]);
    for (int i = LIMIT; i >= 1; i--) {
        ifact[i-1] = (ifact[i] * i) % mod;
    }
}

ll choose(ll n, ll k) {
    return modinv(fact[k] * fact[n-k] % mod) * fact[n] % mod;
}

int main() {
    compute_factorial();
    compute_ifact();
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0;
        return 0;
    }
    n /= 2;
    cout << (modinv(n + 1) * choose(2 * n, n) % mod);
    return 0;
}
