#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;
const int LIMIT = 1000000;
ll factorials[LIMIT + 1];
ll inverse_factorials[LIMIT+1]; // (i!)^-1 % mod

ll powmod(ll base, ll exp) {
    if (exp == 0) return 1;
    return (((exp % 2 == 1 ? base : 1) * powmod((base*base)%mod, exp/2)) % mod);
}

ll choose(int a, int b) {
    // Precompute factorials, then do mod inverse for b! and (a-b)!
    return (((factorials[a] * inverse_factorials[b]) % mod) * inverse_factorials[a-b]) % mod;
}

void compute_factorials() {
    factorials[0] = 1;
    for (int i = 1; i <= LIMIT; i++) {
        factorials[i] = (i * factorials[i-1]) % mod;
    }
}

void compute_inverse_factorials() {
    inverse_factorials[LIMIT] = powmod(factorials[LIMIT], mod-2); // 1/(LIMIT!)
    for (int i = LIMIT; i > 0; i--) {
        inverse_factorials[i-1] = (inverse_factorials[i] * i) % mod;
    }
}

int main() {
    compute_factorials();
    compute_inverse_factorials();
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << choose(a,b) << '\n';
    }
    return 0;
}
