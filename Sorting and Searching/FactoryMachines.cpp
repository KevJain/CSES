#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

bool canMake(vector<int>& machines, ll target, ll time) {
    for (auto m : machines) {
        target -= time / m;
        if (target <= 0) {
            return true;
        }
    }
    //cout << time << " " << target;
    return (target <= 0);
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    while (n--) {
        int m;
        cin >> m;
        machines[n] = m;
    }
    ll lo = 0;
    ll hi = 1e18;
    ll mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        // cout << mid << endl;
        if (canMake(machines, t, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
    return 0;
}
