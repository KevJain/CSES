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
    vector<int> prev(31, 0);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 31; j++) {
            if (x >> j & 1) {
                int diff = min(k, i - prev[j]);
                    if (diff % 2 == 1) {
                        cout << i << ' ' << x << ' ' << diff << ' ' << (1 << j) << endl;
                        out ^= 1 << j;
                    }
                prev[j] = i;
            }
        }
        x = (a*x + b) % c;
    }
    cout << out;
    return 0;
}
