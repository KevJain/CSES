#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int,int>>());
    for (int i = 0; i < m ; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
    }
    vector<vector<bool>> seen(n+1, vector<bool>(2)); // without discount, with discount
    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> pq; // price, city, used discount
    pq.emplace(0LL, 1, false);
    while (!pq.empty()) {
        auto [cost, city, used] = pq.top();
        pq.pop();
        if (seen[city][used]) continue;
        seen[city][used] = true;
        if (city == n) {
            cout << cost;
            return 0;
        }
        for (auto [dest, price] : graph[city]) {
            pq.emplace(cost + price, dest, used);
            if (!used) {
                pq.emplace(cost + price / 2, dest, true);
            }
        }
    }
    cout << "ERROR, not found";
    return 0;
}
