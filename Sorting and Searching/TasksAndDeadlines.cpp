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
    vector<pair<int,int>> tasks; // duration, deadline
    ll out = 0;
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        tasks.emplace_back(a,d);
        out += d;
    }
    sort(tasks.begin(), tasks.end());
    for (ll i = 0; i < n; i++) {
        out -= (n - i) * tasks[i].first;
    }
    cout << out;
    return 0;
}
