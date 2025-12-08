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
    int boys, girls, k;
    cin >> boys >> girls >> k;
    int n = boys + girls + 2; // 1 is source, boys + girls + 2 is sink
    vector<map<int, ll>> graph(n+1, map<int, ll>());
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a+1][b+boys+1]++;
    }
    for (int i = 0; i < boys; i++) {
        graph[1][i + 2]++;
    }
    for (int i = 0; i < girls; i++) {
        graph[boys+i+2][n]++;
    }

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

    // Check residual graph for flow, flow implies pairing
    for (int girl = boys + 2; girl < n; girl++) {
        for (auto [boy, flow] : graph[girl]) {
            if (boy != n && flow == 1) {
                cout << (boy - 1) << ' ' << (girl - boys - 1) << '\n';
            }
        }
    }

    return 0;
}
