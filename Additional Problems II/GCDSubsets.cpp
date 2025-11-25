// Strategy: For each possible divisor from 1 to 2e5, count the number
// of elements that are multiples of this number. Then the number of 
// subsets with gcd a multiple of this divisor is 2^size - 1. Compute backwards
// and then subtract the found answer from each of the multiples of this divisor

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

const int LIMIT = 2e5;
const ll mod = 1e9 + 7;
vector<vector<int>> divisors(LIMIT+1, vector<int>());

void compute_divisors() {
    for (int i = 1; i <= LIMIT; i++) {
        for (int m = i; m <= LIMIT; m += i) {
            divisors[m].push_back(i);
        }
    }
}

ll powmod(ll base, ll exp) {
    ll out = 1;
    while (exp) {
        if (exp & 1) {
            out = (out * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    compute_divisors();
    int n;
    cin >> n;
    vector<ll> count(LIMIT+1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (auto d : divisors[x]) count[d]++;
    }
    vector<ll> out(LIMIT+1);
    for (int d = LIMIT; d >= 1; d--) {
        if (count[d] > 0) {
            out[d] = powmod(2, count[d]) - 1;
            for (int m = d+d; m <= LIMIT; m += d) {
                out[d] = (out[d] - out[m] + mod) % mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << out[i] << ' ';
    }
    return 0;
}
