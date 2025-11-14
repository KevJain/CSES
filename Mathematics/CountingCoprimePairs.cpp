#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;

const int LIMIT = 1000000;
vector<vector<int>> primes(LIMIT+1, vector<int>());

void sieve() {
    for (int p = 2; p <= LIMIT; p ++) {
        if (!primes[p].empty()) continue;
        for (int m = p; m <= LIMIT; m += p) {
            primes[m].push_back(p);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    ll n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int,int> freq; // frequency count
    for (auto &a : arr) {
        cin >> a;
        freq[a]++;
    }
    ll count = 0;
    // Populate subset sizes
    vector<int> multiples(LIMIT+1); // number of elements of arr that are multiples
    for (auto& [num, f] : freq) {
        int prime_divisors = primes[num].size();
        for (int i = 1; i < 1 << prime_divisors; i++) { // mask
            int divisor = 1;
            for (int j = 0; j < prime_divisors; j++) {
                if (i & (1 << j)) {
                    divisor *= primes[num][j];
                }
            }
            multiples[divisor]+=f;
        }
    }
    for (auto& [num, f] : freq) {
        if (num == 1) {
            count += f * (n-1);
            continue;
        }
        int prime_divisors = primes[num].size();
        int noncoprime = 0;
        for (int i = 1; i < 1 << prime_divisors; i++) { // mask
            int divisor = 1;
            for (int j = 0; j < prime_divisors; j++) {
                if (i & (1 << j)) {
                    divisor *= primes[num][j];
                }
            }
            int sz = __builtin_popcount(i);
            noncoprime += (sz % 2 == 1) ? multiples[divisor] : -multiples[divisor];
        }
        count += f * (n - noncoprime);
    }
    cout << count / 2;
}
