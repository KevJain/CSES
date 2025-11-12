#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

void dfs(int node, vector<bool>& seen, vector<vector<int>>& graph) {
    seen[node] = true;
    for (auto child : graph[node]) {
        if (seen[child]) continue;
        dfs(child, seen, graph);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> seen(n+1);
    vector<int> components; // single node from each component
    for (int i = 1; i <= n; i ++) {
        if (seen[i]) continue;
        dfs(i, seen, graph);
        components.push_back(i);
    }
    int new_roads = components.size() - 1;
    cout << new_roads << '\n';
    for (int i = 1; i < components.size(); i ++) {
        cout << components[i-1] << ' ' << components[i] << '\n';
    }
    return 0;
}
