#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

ll slope(pair<ll,ll> line) {
    return line.second - line.first;
}

double intersect(pair<ll,ll> line1, pair<ll,ll> line2, ll m) {
    return (1.0) * (line2.first - line1.first) * m / (line1.second - line2.second + line2.first - line1.first);
}

ll eval(pair<ll,ll> line, ll x, ll m) {
    return (line.second - line.first) * x / m + line.first;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> lines(n);
    for (ll i = 0; i < n; i++) {
        ll y1, y2;
        cin >> y1 >> y2;
        lines[i] = {y1,y2};
    }
    vector<pair<ll,ll>> hull_lines;
    vector<double> hull_pts;
    sort(lines.begin(), lines.end(), greater<pair<ll,ll>>()); // descending by y1
    hull_lines.push_back(lines[0]); // Greatest y1 always is in hull
    hull_pts.push_back({0}); // this point will never be removed
    for (ll i = 1; i < n; i++) { // hull is non empty and valid for lines[:i]
        double x_intersect = intersect(lines[i], hull_lines.back(), m);
        while (slope(lines[i]) > slope(hull_lines.back()) && x_intersect <= hull_pts.back()) {
            hull_lines.pop_back();
            hull_pts.pop_back();
            x_intersect = intersect(lines[i], hull_lines.back(), m);
        }
        if (slope(lines[i]) > slope(hull_lines.back())) {
            hull_pts.push_back(x_intersect);
            hull_lines.push_back(lines[i]);
        }
    }
    
    auto print = [] (auto& v) {
        for (auto e : v) {
            cout << e << ' ';
        }
        cout << endl;
    };

    //print(hull_pts);
    //print(hull_lines);
    ll j = 0; // current line
    for (ll i = 0; i <= m; i++) {
        while (j + 1 < hull_pts.size() && hull_pts[j+1] < i) {
            j++;
        }
        cout << eval(hull_lines[j], i, m) << ' ';
    }

    return 0;
}
