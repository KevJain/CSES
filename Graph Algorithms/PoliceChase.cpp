// Edmonds-Karp: Use BFS on residual graph to find augmenting path

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;

ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<map<int, ll>> graph(n+1, map<int, ll>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b]++;
        graph[b][a]++;
    }
    auto original = graph;
    ll total_flow = 0;

    while (true) {
        vector<pair<int, ll>> prev(n+1); // previous node, flow
        prev[1] = {0, inf};
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == n) break;
            for (auto [neighbour, flow] : graph[cur]) {
                if (prev[neighbour].first != 0) continue;
                prev[neighbour] = {cur, min(prev[cur].second, flow)};
                q.push(neighbour);
            }
        }

        ll augmented_flow = prev[n].second;
        if (augmented_flow == 0) break;
        total_flow += augmented_flow;
        int cur = n;
        while (cur != 1) {
            int prev_node = prev[cur].first;
            graph[prev_node][cur] -= augmented_flow;
            if (graph[prev_node][cur] == 0) {
                graph[prev_node].erase(cur);
            }
            graph[cur][prev_node] += augmented_flow;
            cur = prev_node;
        }
    }
    cout << total_flow << '\n';

    // Determine edges in cut from original
    vector<bool> seen(n+1);
    seen[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto [neighbour, _discard] : graph[cur]) {
            if (seen[neighbour]) continue;
            seen[neighbour] = true;
            q.push(neighbour);
        }
    }
    for (int i = 1; i < n; i++) {
        for (auto [neighbour, _discard] : original[i]) {
            if (i < neighbour && seen[i] != seen[neighbour]) {
                cout << i << ' ' << neighbour << '\n';
            }
        }
    }

    return 0;
}
