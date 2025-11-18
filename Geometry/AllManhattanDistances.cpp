#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef __int128_t ll;
using namespace std;

ll dists(vector<int>& p) {
    sort(p.begin(), p.end());
    ll out = 0;
    for (int i = 0; i < p.size() - 1; i++) {
        out += (ll)(p[i+1] - p[i]) * (i+1) * (p.size()-i-1);
    }
    return out;
}


int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll out = dists(x) + dists(y);
    vector<int> print;
    if (!out) {
        cout << 0;
        return 0;
    }
    while (out) {
        print.push_back((int)(out % 10));
        out /= 10;
    }
    for (auto it = print.rbegin(); it != print.rend(); it++) {
        cout << (*it);
    }
    return 0;
}
