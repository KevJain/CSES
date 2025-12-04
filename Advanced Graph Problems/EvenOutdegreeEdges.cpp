// For each connected component, ensure each the total number of edges is even
// Arbitrarily root each component and dfs
// Do a postorder traversal of the dfs tree, and orient each backedge downwards
// After processing each node's children, it will either have an even or odd outdegree
// Orient the edge towards to parent to make this node's outdegree even
// Finally, when we get to the root, it is guaranteed to have even outdegree because
// we will have processed every edge in the component. Since the sum of outdegrees of the component
// equals the number of edges in the component, then since every other node has an even outdegree,
// the root must also have even outdegree since the total number of edges is even.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
typedef long long ll;
using namespace std;

void impossible() {
    cout << "IMPOSSIBLE";
    exit(0);
}

int dfs(int node, int parent, int d, vector<vector<int>>& graph, vector<pair<int,int>>& edges, vector<int>& depth) {
    depth[node] = d;
    int outdeg = 0;
    for (int child : graph[node]) {
        if (child == parent) continue;
        if (depth[child] > depth[node]) { // Found backedge, orient outwards
            edges.push_back({node, child});
            outdeg++;
        } else if (depth[child] == -1) {
            outdeg += dfs(child, node, d + 1, graph, edges, depth);
        }
    }
    if (parent == 0) {
        if (outdeg % 2 == 1) impossible();
        return 0;
    }
    if (outdeg % 2 == 1) {
        edges.push_back({node, parent});
        return 0;
    }
    edges.push_back({parent, node});
    return 1;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m % 2 == 1) impossible();
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0 ; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<pair<int, int>> edges;
    vector<int> depth(n+1, -1);
    for (int i = 1; i <= n; i++) {
        if (depth[i] != -1) continue;
        dfs(i, 0, 0, graph, edges, depth);
    }
    for (auto [n1, n2] : edges) {
        cout << n1 << ' ' << n2 << '\n';
    }

    return 0;
}
