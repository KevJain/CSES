#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    ll min_x = 1e18;
    ll max_x = -1e18;
    ll min_y = 1e18;
    ll max_y = -1e18;
    for (int i = 0; i < n; i++) {
        ll a, b, x, y;
        cin >> a >> b;
        x = a + b;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        y = a - b;
        min_y = min(min_y, y);
        max_y = max(max_y, y);
        cout << max(max_x - min_x, max_y - min_y) << '\n';
    }

    return 0;
}
