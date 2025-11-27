#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> graph(n+1, vector<pair<int,ll>>());
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    vector<int> seen(n+1);
    vector<ll> out;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [price, city] = pq.top();
        pq.pop();
        if (seen[city] >= k) continue;
        seen[city]++;
        if (city == n) out.push_back(price);
        for (auto [neighbour, fcost] : graph[city]) {
            if (seen[neighbour] < k) {
                pq.push({price + fcost, neighbour});
            }
        }
    }
    for (auto cost : out) {
        cout << cost << ' ' ;
    }
    return 0;
}
