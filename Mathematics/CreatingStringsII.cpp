#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

const int LIMIT = 1e6;
ll factorial[LIMIT + 1] = {};
ll ifactorial[LIMIT + 1] = {};
ll mod = 1e9+7;

ll powmod(ll base, ll exp) {
    ll out = 1;
    while (exp) {
        if (exp & 1) {
            out *= base;
            out %= mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return out;
}

ll modinv(ll a) {
    return powmod(a, mod - 2);
}

void compute_factorial() {
    factorial[0] = 1;
    for (int i = 1; i <= LIMIT; i++) {
        factorial[i] = (i*factorial[i-1])%mod;
    }
}

void compute_ifactorial() {
    ifactorial[LIMIT] = modinv(factorial[LIMIT]);
    for (int i = LIMIT - 1; i >= 0; i--) {
        ifactorial[i] = (ifactorial[i+1] * (i+1)) % mod;
    }
}

int main() {
    compute_factorial();
    compute_ifactorial();
    string s;
    cin >> s;
    int count[26] = {};
    for (char& c : s) {
        count[c-'a']++;
    }
    ll out = factorial[s.size()];
    for (int i = 0; i < 26; i ++) {
        out = (out * ifactorial[count[i]]) % mod;
    }
    cout << out;
    return 0;
}
