#include <iostream>
#include <vector>
#include <string>
#include <numeric>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> pts(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pts[i] = {x,y};
    }
    ll area = 0;
    for (int i = 1; i < n; i++) {
        area += (pts[i].first - pts[i-1].first) * (pts[i].second + pts[i-1].second);
    }
    area += (pts[0].first - pts[n-1].first) * (pts[0].second + pts[n-1].second);
    area = abs(area);
    // By Pick's Theorem, Area = # lattice points + (#boundary points / 2) - 1
    // We need to determine boundary points
    ll boundary = n;
    for (int i = 1; i < n; i++) {
        boundary += gcd(pts[i].first - pts[i-1].first, pts[i].second - pts[i-1].second) - 1;
    }
    boundary += gcd(pts[0].first - pts[n-1].first, pts[0].second - pts[n-1].second) - 1;
    cout << (area / 2 - boundary / 2 + 1) << ' ' <<  boundary;
    return 0;
}
