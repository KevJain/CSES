#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll chosen = 0;
    while (chosen * (chosen - 1) / 2 < k) {
        chosen++;
    }
    ll pos = (chosen * (chosen - 1) / 2 - k);
    for (int i = chosen; i > 1; i--) {
        if (i == pos + 1) cout << 1 << ' ';
        cout << i << ' ';
    }
    if (pos == 0 && chosen > 0) cout << 1 << ' ';
    for (int i = chosen + 1; i <= n; i++) cout << i << ' ';

    return 0;
}
