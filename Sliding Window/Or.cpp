#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    ll x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    int out = 0;
    int prev[31] = {};
    for (int i = 1; i <= n; i ++) {
        int p = 0;
        while (1 << p <= x) {
            if (x >> p & 1) {
                prev[p] = i;
            }
            p++;
        }
        x = (a*x + b) % c;
        if (i < k) continue;
        int here = 0;
        for (int j = 0; j < 31; j ++) {
            if (prev[j] && prev[j] + k > i) {
                here |= 1 << j;
            }
        }
        //cout << x << ' ' << here << endl;
        out ^= here;
    }
    cout << out;
    return 0;
}
