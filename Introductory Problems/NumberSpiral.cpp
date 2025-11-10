#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    ll x, y;
    ll major, minor, diff;
    int sgn;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        major = max(x,y);
        minor = min(x, y);
        diff = major - minor;
        sgn = (x == major) == (major % 2 == 0) ? 1 : -1;
        cout << (major * major) - major + 1 + (sgn * diff) << " ";
    }
    return 0;
}
