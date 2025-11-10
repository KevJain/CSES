#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll sum;
    sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << "NO" << "\n";
        return 0;
    }
    ll target = sum / 2;
    ll cur = n;
    ll used = -1;
    vector<int> first = {};
    while (target > 0) {
        if (cur <= target) {
            target -= cur;
            first.push_back(cur);
            cur -= 1;
        } else {
            first.push_back(target);
            used = target;
            target = 0;
        }
    }
    cout << "YES\n" << first.size() << '\n';
    for (auto x : first) {
        cout << x << " ";
    }
    cout << endl << n - first.size() << endl;
    while (cur > 0) {
        if (cur != used) {
            cout << cur << ' ';
        }
        cur--;
    }
    return 0;
}
