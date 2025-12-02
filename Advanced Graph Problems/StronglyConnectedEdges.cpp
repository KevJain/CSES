// Try to construct a chain decomposition of the graph. If we find such a decomposition,
// it induces our desired orientation. Otherwise we detect bridges and no orientation exists.
// Chain decomposition: Construct a DFS tree on the graph. Then traverse in order of DFS traversal
// and for each edge not in DFS tree, follow edge and then traverse DFS tree orienting edges along the way
// until we reach a vertex that has been seen before.
// Any edge in the DFS tree not explored during this process is a bridge.
#include <iostream>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

void dfs(int cur, vector<set<int>>& graph, vector<bool>& seen, vector<int>& parent, vector<int>& order) {
    order.push_back(cur);
    for (auto it = graph[cur].begin(); it != graph[cur].end();) {
        int neighbour = *it;
        if (!seen[neighbour]) {
            seen[neighbour] = true;
            parent[neighbour] = cur;
            it = graph[cur].erase(it);
            graph[neighbour].erase(cur);
            dfs(neighbour, graph, seen, parent, order);
        } else {
            ++it;
        }
    }
}

void impossible() {
    cout << "IMPOSSIBLE";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n+1, set<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector<int> order;
    vector<bool> seen(n+1);
    vector<int> parent(n+1);
    seen[1] = true;

    dfs(1, graph, seen, parent, order);

    if (order.size() != n) impossible(); // Graph not connected
    seen.assign(n+1, false);
    vector<pair<int,int>> o_edges;

    for (auto node : order) {
        seen[node] = true;
        for (auto desc : graph[node]) {
            o_edges.emplace_back(node, desc);
            graph[desc].erase(node);
            while (!seen[desc]) {
                seen[desc] = true;
                o_edges.emplace_back(desc, parent[desc]);
                int next_desc = parent[desc];
                parent[desc] = 0;
                desc = next_desc;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (parent[i] != 0) impossible(); // Edge (i, parent[i]) is a bridge, no orientation exists
    }
    for (auto [a, b] : o_edges) {
        cout << a << ' ' << b << '\n';
    }

    return 0;
}
