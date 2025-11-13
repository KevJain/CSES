#include <iostream>
#include <string>
typedef long long ll;
using namespace std;


int powmod(ll a, ll b, ll mod) {
    ll out = 1;
    while (b > 0) {
        if (b & 1) {
            out = (out * a) % mod;
        }
        b >>= 1;
        a = (a*a) % mod;

    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll exponent = powmod(b,c,1e9+6);
        ll ans = powmod(a,exponent,1e9+7);
        cout << ans << '\n';
    }

    return 0;
}
