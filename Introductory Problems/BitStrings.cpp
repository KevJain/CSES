#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int power(ll base, int e, int mod) {
    //cout << base << " " << e << " " << mod << endl;
    if (e == 1) {
        return base;
    }
    if (e % 2 == 0) {
        return power((base*base)%mod, e / 2, mod);
    }
    return base * power(base, e - 1, mod) % mod;
}

int main() {
    ll n;
    cin >> n;
    cout << power(2, n, 1000000007);
    return 0;
}
