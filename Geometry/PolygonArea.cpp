#include <iostream>
#include <vector>
#include <string>
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
    cout << abs(area);
    return 0;
}
