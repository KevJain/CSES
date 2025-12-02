// Create tree with BFS, then iterate through tree from a leaf
// Keep track of two sets: those already seen and those not seen
// When traversing the tree, each edge has one endpoint seen
// and one not seen. Check if there are any edges connecting
// seen to unseen besides this current edge, if not then this
// edge is necessary. Then, add the new city to seen set
// and update 'crossing' edge set as necessary
// i.e. add new edges from this city, remove edges coming into it

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
typedef long long ll;
using namespace std;

void dfs(int cur, int prev, vector<vector<int>>& tree, set<int>& cross_edges) {

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    vector<bool> seen(n+1);
    q.push_back(1);
    seen[1] = true;
    vector<vector<int>> tree(n+1, vector<int>());
    int leaf = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        leaf = cur;
        for (int neighbour : graph[cur]) {
            if (seen[neighbour]) continue;
            seen[neighbour] = true;
            tree[cur].push_back(neighbour);
            q.push(neighbour);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;
        // Check if graph is not connected
        for (int k = 1; k <= n; k++) {
            for (auto j : graph[k]) {
                cout << k << ' ' << j << '\n';
            }
        }
        return 0;
    }

    vector<int> cut = {leaf};
    int prev = 0;
    set<int> cross_edges;
    for (auto i : graph[leaf]) cross_edges.insert(i);
    dfs(leaf, 0, cross_edges);


    return 0;
}
