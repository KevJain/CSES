#include <iostream>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
ll getMinDiff(int a[20], ll s, ll cur, int j, int n) {
    ll minDiff = s - 2 * cur;
    if (j == n) {
        return minDiff;
    }
    minDiff = min(minDiff, getMinDiff(a, s, cur, j + 1, n));
    if (cur + a[j] <= s / 2) {
        minDiff = min(minDiff, getMinDiff(a, s, cur + a[j], j + 1, n));
    }
    return minDiff;
}

int main() {
    int n;
    int a[20];
    ll s = 0, min_diff = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    min_diff = getMinDiff(a, s, 0, 0, n);
    cout << min_diff;
    return 0;
}
