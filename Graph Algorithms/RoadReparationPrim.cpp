// Prim's: add unseen vertex with lowest cost

#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> graph(n+1, vector<pair<int,ll>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    // Begin with vertex 1
    ll cost = 0;
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});
    vector<bool> seen(n+1);
    int tree_size = 0;
    while (!pq.empty()) {
        auto [road_cost, city] = pq.top();
        pq.pop();
        if (seen[city]) continue;
        cost += road_cost;
        tree_size++;
        seen[city] = true;
        for (auto [neighbour, dist] : graph[city]) {
            if (!seen[neighbour]) {
                pq.push({dist, neighbour});
            }
        }
    }
    if (tree_size < n) {
        cout << "IMPOSSIBLE";
    } else {
        cout << cost;
    }
    return 0;
}
