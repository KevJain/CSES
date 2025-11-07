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
    for (int i = 0; i < n; i ++) {
        int windows = min(i + 1, k) - max(0,i-n+k);
        //cout << i << ' ' << windows << endl;
        if (windows & 1) {
            out ^= x;
        }
        x = (a*x + b) % c;
    }
    cout << out;
    return 0;
}
