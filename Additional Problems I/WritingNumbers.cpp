#include <iostream>
#include <string>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;

template <typename T>
void print(vector<T>& v) {
    for (auto & e : v) {
        cout << e << ' ';
    }
    cout << endl;
}

bool canWrite(ll cand, ll n, vector<ll> c) {
    vector<int> digits;
    cout << cand << endl;
    while (cand > 0) {
        digits.push_back(cand%10);
        cand /= 10;
    }
    print(digits);
    ll used = c[digits.size()-1];
    int leading = 0;
    for (int d = digits.size() - 1; d > 0; d--) {
        used += digits[d] * c[d-1] * (1 + leading);
        if (digits[d] == 1) leading++;
    }
    if (digits[0] == 1) used++;
    return used <= n;
}

int main() {
    // 1 will always be the limiting factor, so the question is
    // using n 1s, what is the largest number we can write?
    // Binary search on the answer: given m, can we write up to m with n 1s?
    // Count digits here: for all numbers with i digits, we use c(i) 1s, where
    // c(1) = 1, c(n) = 10^(n-1) + 8 * c(n)
    // Count ascending until we reach the leading digit
    // Then we descend from the leading digit, keep track of the number of leading 1s
    // as every number on the way down will have to use one of these leading 1s

    int n;
    cin >> n;
    ll lo = 1;
    ll hi = 1e18;
    vector<ll> c = {0};
    while (c.back() < 1e18) {
        c.push_back(pow(10, c.size()-1) + 10 * c.back());
    }
    print(c);
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (canWrite(mid, n, c)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo;
    return 0;
}
