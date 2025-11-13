#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

const int LIMIT = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n;
    int count[LIMIT+1] = {};
    int max_divisor = 1;
    int max_x = 1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (count[x] == 1 && x > max_divisor) {
            max_divisor = x;
        }
        count[x]++;
        if (x > max_x) {
            max_x = x;
        }
    }
    int lim = max_x / 2 + 1;
    for (int d = max_divisor + 1; d <= lim; d++) {
        int seen = 0;
        for (int d2 = d; d2 <= max_x; d2+=d) {
            seen += count[d2];
        }
        if (seen > 1) {
            max_divisor = d;
        }
    }
    cout << max_divisor;
}
