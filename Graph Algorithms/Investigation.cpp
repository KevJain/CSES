#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

struct Trip {
    ll price = 1e18;
    ll num_routes = 0;
    int min_len = 0;
    int max_len = 0;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> graph(n+1, vector<pair<int,ll>>());
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    vector<Trip> trips(n+1);
    vector<bool> seen(n+1);
    trips[1] = {0, 1};
    // pq = price, city
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [price, city] = pq.top();
        pq.pop();
        if (seen[city]) continue;
        seen[city] = true;
        for (auto [neighbour, fprice] : graph[city]) {
            if (trips[neighbour].price > price + fprice) {
                trips[neighbour] = trips[city];
                trips[neighbour].price = price + fprice;
                trips[neighbour].min_len++;
                trips[neighbour].max_len++;
            } else if (trips[neighbour].price == price + fprice) {
                trips[neighbour].num_routes += trips[city].num_routes;
                trips[neighbour].num_routes %= mod;
                trips[neighbour].min_len = min(trips[neighbour].min_len, trips[city].min_len + 1);
                trips[neighbour].max_len = max(trips[neighbour].max_len, trips[city].max_len + 1);
            }
            pq.push({price+fprice, neighbour});
        }
    }
    cout << trips[n].price << ' ' << trips[n].num_routes << ' ' << trips[n].min_len << ' ' << trips[n].max_len;
    return 0;
}
