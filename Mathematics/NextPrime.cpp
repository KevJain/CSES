#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
typedef long long ll;
using namespace std;

// Numbers are too large to sieve, instead search sequentially for the next prime
// The largest gap between primes less than 10^12 is 1132, so we check at most 566 more numbers
// Each check is O(sqrt(n))

unordered_map<ll,ll> seen = {{1,2}}; // Caches results

bool is_prime(ll m) {
    ll limit = llround(sqrt(m)) + 1;
    for (int i = 3; i < limit; i+=2) {
        if (m % i == 0) return false;
    }
    return true;
}

ll next_prime(ll n) {
    if (seen.count(n)) {
        return seen[n];
    }
    ll cand = n + (n%2 + 1);
    if (is_prime(cand)) {
        seen[n] = cand;
    } else {
        seen[n] = next_prime(cand);
    }
    return seen[n];
}

void solve(ll n) {
    if (n == 1) {
        cout << 2 << '\n';
        return;
    }
    cout << next_prime(n) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}
