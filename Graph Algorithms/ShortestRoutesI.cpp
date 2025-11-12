#include <iostream>
#include <vector>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> graph(n+1, vector<pair<int,ll>>());
    for (int i = 0; i < m; i ++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    ll inf = 1e18;
    vector<ll> dists(n+1, inf);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});
    dists[1] = 0;
    int found = 0;
    while (found < n && !pq.empty()) {
        auto [dist, city] = pq.top();
        pq.pop();
        if (dist > dists[city]) continue;
        found++;
        for (auto [neighbour, cost] : graph[city]) {
            ll neighbour_dist = dist + cost;
            if (neighbour_dist < dists[neighbour]) {
                dists[neighbour] = neighbour_dist;
                pq.push({neighbour_dist, neighbour});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dists[i] << ' ';
    }

    return 0;
}
