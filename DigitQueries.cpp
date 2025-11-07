#include <iostream>
#include <string>
#include <cmath>
typedef long long ll;
using namespace std;

ll power(ll b, int e) {
    ll out = 1;
    while (e--) {
        out *= b;
    }
    return out;
}

int main() {
    ll d, num, digit;
    int t;
    ll q;
    cin >> t;
    while (t--) {
        cin >> q;
        if (q < 10) {
            cout << q << '\n';
            continue;
        }
        d = 1;
        while (d * (power(10, d) - power(10, d - 1)) < q) {
            q -= d * (power(10,d) - power(10, d - 1));
            d += 1;
        }
        num = power(10, d - 1) + (q - 1) / d;
        if (q % d == 0) {
            digit = 0;
        } else {
            digit = d - (q % d);
        }
        //cout << num << endl;
        //cout << digit << endl;
        while (digit-- > 0) {
            num /= 10;
        }
        cout << num % 10 << '\n';
    }
    return 0;
}
