#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, x;
    cin >> x >> n;
    set<int> lights = {0, x};
    vector<int> out(n);
    vector<int> added(n);
    for (int i = 0; i < n; i++) {
        int light;
        cin >> light;
        lights.insert(light);
        added[i] = light;
    }
    int max_l = 1;
    auto it = lights.begin();
    int prevl = *it;
    while (++it != lights.end()) {
        int cur = *it;
        max_l = max(cur - prevl, max_l);
        prevl = cur;
    }
    for (int i = n - 1; i >= 0; i--) {
        out[i] = max_l;
        auto it = lights.find(added[i]);
        int new_l = *next(it) - *prev(it);
        lights.erase(added[i]);
        max_l = max(max_l, new_l);
    }
    for (auto gap : out) {
        cout << gap << ' ';
    }
    return 0;
}
