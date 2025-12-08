// ((1,1),(1,0))^n = ((F_{n+1}, F_n), (F_n, F_{n-1}))

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;
vector<ll> mult(vector<ll>& a, vector<ll>& b) {
    vector<ll> out(4);
    out[0] = (a[0] * b[0] + a[1] * b[2]) % mod;
    out[1] = (a[0] * b[1] + a[1] * b[3]) % mod;
    out[2] = (a[2] * b[0] + a[3] * b[2]) % mod;
    out[3] = (a[2] * b[1] + a[3] * b[3]) % mod;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> cur = {1, 0, 1, 0};
    vector<ll> base = {1, 1, 1, 0};
    while (n > 0) {
        if (n & 1) {
            cur = mult(cur, base);
        }
        base = mult(base, base);
        n >>= 1;
    }
    cout << cur[1];
    return 0;
}
