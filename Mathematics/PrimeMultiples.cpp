#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> primes(k);
    for (auto &p : primes) {
        cin >> p;
    }
    ll count = 0;
    // Iterate over all subsets
    for (unsigned int i = 1; i < 1 << k; i++) {
        ll multiple = 1;
        bool bigger = false;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                if (n / multiple >= primes[j]) { // check limit
                    multiple *= primes[j];
                } else { // multiple will be greater than n
                    bigger = true;
                    break;
                }
            }
        }
        if (bigger) continue;
        int cnt = __builtin_popcount(i);
        count += (cnt % 2 == 1) ? (n / multiple) : -(n / multiple);
    }
    cout << count;
}
