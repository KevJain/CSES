#include <iostream>
#include <set>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> tickets = {};
    int ins, p;
    for (int i = 0; i < n; i ++) {
        cin >> ins;
        tickets.insert(ins);
    }
    for (int i = 0; i < m; i ++) {
        cin >> p;
        auto idx = tickets.upper_bound(p);
        if (idx == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            idx--;
            cout << *idx << '\n';
            tickets.erase(idx);
        }
    }
    return 0;
}
