// Determine if the entire graph is a single strongly connected component
// Use Kosaraju's Algorithm:
// Do a pseudo-topological sort of the graph with dfs (do nothing upon finding cycle rather than exit)
// Go through each node and assign them to a 'component' recursively by traversing the reverse graph

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<int> ordering;
vector<vector<int>> graph;
vector<bool> seen;
vector<vector<int>> rgraph;
vector<int> component;

void visit(int x) {
    if (seen[x]) return;
    seen[x] = true;
    for (int neighbour : graph[x]) {
        visit(neighbour);
    }
    ordering.push_back(x);
}

void assign(int cur, int root) {
    if (component[cur] != -1) return;
    component[cur] = root;
    for (int in_neighbour : rgraph[cur]) {
        assign(in_neighbour, root);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph.assign(n+1, vector<int>());
    rgraph.assign(n+1, vector<int>());
    seen.assign(n+1, false);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        visit(i);
    }
    reverse(ordering.begin(), ordering.end());
    component.assign(n+1, -1);
    int label = 0;
    for (int i = 0; i < n; i++) {
        if (component[ordering[i]] != -1) continue;
        assign(ordering[i], ++label);
    }
    cout << label << '\n';
    for (int i = 1; i <= n; i++) {
        cout << component[i] << ' ';
    }

    return 0;
}
