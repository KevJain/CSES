#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

ll lcm_mod(set<int>& nums) {
    map<int, int> primes; // prime : max exp
    for (auto n : nums) {
        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                int power = 0;
                while (n % p == 0) {
                    n /= p;
                    power += 1;
                }
                primes[p] = max(primes[p], power);
            }
        }
        if (n != 1) {
            primes[n] = max(primes[n], 1);
        }
    }
    ll out = 1;
    for (auto& [prime, power] : primes) {
        for (int i = 0; i < power; i ++) {
            out = (out * prime) % mod;
        }
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<int> dest(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> dest[i];
    }
    vector<bool> seen(n+1);
    set<int> cycles;
    for (int i = 1; i <= n; i++) {
        if (seen[i] || dest[i] == i) continue;
        int cur = dest[i];
        int len = 1;
        while (cur != i) {
            seen[cur] = true;
            cur = dest[cur];
            len++;
        }
        cycles.insert(len);
    }
    ll l = 1;    
    cout << lcm_mod(cycles);
    return 0;
}
