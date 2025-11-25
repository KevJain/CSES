// Correct O(N^2) solution for testing

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> boards(n);
    for (auto& a : boards) {
        cin >> a;
    }
    ll out = 0;
    for (int l = 0; l < boards.size(); l++) {
        ll mn = boards[l];
        for (int r = l; r < boards.size(); r++) {
            mn = min(mn, boards[r]);
            out = max(out, (r-l+1) * mn);
        }
    }
    cout << out;
    return 0;
}
