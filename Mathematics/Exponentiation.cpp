#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

void solve(ll a, ll b) {
    ll out = 1;
    while (b > 0) {
        if (b & 1) {
            out = (out * a) % mod;
        }
        b >>= 1;
        a = (a*a) % mod;

    }
    cout << out << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        ll a, b;
        cin >> a >> b;
        solve(a,b);
    }

    return 0;
}
