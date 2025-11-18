#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
typedef long long ll;
using namespace std;
int inf = 1e9;
ll LIMIT = 1e12;

void print(vector<pair<ll, int>> v) {
    for (auto& [a, b] : v) {
        cout << "(" << a << "," << b << ")";
    }
    cout << '\n';
}

int main() {
    int t;
    unordered_set<ll> seen;
    cin >> t;
    ll i = 1;
    while (i * (i+1) / 2 <= LIMIT) {
        seen.insert(i*(i+1)/2);
        i++;
    }
    // Two sum
    while (t--) {
        ll n;
        cin >> n;
        if (n == 2) {
            cout << 2 << '\n';
            continue;
        }
        if (seen.count(n)) {
            cout << 1 << '\n';
            continue;
        }
        // By Gauss, every number is the sum of 3 triangular numbers
        // Then the question remains whether n is the sum of exactly 2
        // If it were, then n = a(a+1)/2 + b(b+1)/2, for some a,b
        // Equivalently, 8n + 2 = (2a+1)^2 + (2b+1)^2, so 8n+2 is the sum of
        // two odd squares. But all squares are equivalent to 0, 1, or 4 mod 8
        // so if any squares sum to 8n+2, they will be odd squares and we thus have 
        // two triangular numbers. To determine whether any squares sum to 8n+2,
        // prime factorize and use Jacobi's two squares theorem
        vector<pair<long long, int>> pf; // (prime, exp)
        int exp = 0;
        ll cpy = 8*n + 2;
        for (ll p = 2; p * p <= cpy; p++) {
            exp = 0;
            while (cpy % p == 0) {
                exp += 1;
                cpy /= p;
            }
            if (exp > 0) {
                pf.push_back({p, exp});
            }
        }
        if (cpy > 1) pf.push_back({cpy, 1});

        bool onemodfour = false;
        bool valid = true;
        for (auto [prime, exp] : pf) {
            if (prime % 4 == 1) onemodfour = true;
            else if (prime % 4 == 3 && exp % 2 == 1) valid = false;
        }
        //print(pf);
        if (valid) {
            cout << 2;
        } else {
            cout << 3;
        }
        cout << '\n';
    }
    return 0;
}
