#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    priority_queue<pair<int,int>> players;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m > 0) players.emplace(m, i+1);
    }
    vector<pair<int,int>> matches;
    vector<pair<int,int>> buf;
    while (!players.empty()) {
        auto [remaining, id] = players.top();
        players.pop();
        for (int i = 0; i < remaining; i++) {
            if (players.empty()) {
                cout << "IMPOSSIBLE";
                return 0;
            }
            auto [oremaining, oid] = players.top();
            players.pop();
            matches.emplace_back(id, oid);
            if (oremaining > 1) {
                buf.emplace_back(oremaining - 1, oid);
            }
        }
        while (!buf.empty()) {
            players.push(buf.back());
            buf.pop_back();
        }
    }
    cout << matches.size() << '\n';
    for (auto [p1, p2] : matches) {
        cout << p1 << ' ' << p2 << '\n';
    }

    return 0;
}
