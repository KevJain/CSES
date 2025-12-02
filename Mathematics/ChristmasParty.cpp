#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll mod = 1e9 + 7;
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0; return 0;
    }
    ll pp = 0;
    ll p = 1;
    for (int i = 3; i <= n; i++) {
        ll next = (i-1) * (p + pp);
        next %= mod;
        pp = p;
        p = next;
    }
    cout << p;
    return 0;
}
