#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    int b = 0;
    ll count = 0;
    while (1LL << b <= n) {
        count += (n >> (b+1)) * (1LL<<b);
        if (n >> b & 1) {
            count += 1 + (((1LL << b) - 1) & n);
        }
        b++;
    }
    cout << count;
    return 0;
}
