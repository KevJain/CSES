#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int t, n;
    cin >> t;
    ll c[1000001][2] = {};
    c[1][0] = 1; c[1][1] = 1;
    for (int j = 2; j < 1000001; j++) {
        c[j][0] = (4 * c[j-1][0] + c[j-1][1]) % mod;
        c[j][1] = (c[j-1][0] + 2 * c[j-1][1]) % mod;
    }
    for (int i = 0; i < t; i ++) {
        cin >> n;
        cout << ((c[n][0] + c[n][1]) % mod) << '\n';
    }
    return 0;
}
