#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll mx = -1000000000;
    ll cur = 0;
    int m;
    while (n--) {
        cin >> m;
        cur += m;
        mx = max(mx, cur);
        if (cur < 0) {
            cur = 0;
        }
    }
    cout << mx;
    return 0;
}
