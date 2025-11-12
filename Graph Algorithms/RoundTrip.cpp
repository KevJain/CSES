#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
vector<int> path;

int dfs(int cur, int prev, vector<bool>& seen, vector<vector<int>>& graph) {
    //cout << prev << "->" << cur <<endl;
    if (seen[cur]) {
        path.push_back(cur);
        return cur;
    }
    seen[cur] = true;
    for (auto neighbour : graph[cur]) {
        if (neighbour == prev) continue;
        int res = dfs(neighbour, cur, seen, graph);
        if (res == -2) {
            return -2;
        }
        if (res != -1) { // cycle found AND this node is on the path
            path.push_back(cur);
            if (res == cur) { // cycle found and completed here
                return -2;
            }
            return res;
        }
    }
    return -1;
}

int main() {
    // Idea: use DFS until we find a previously marked node, then unwind
    // return -1 if DFS fails
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i ++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> seen(n+1);
    for (int start = 1; start <= n; start ++) {
        if (seen[start] != 0) continue;
        dfs(start, 0, seen, graph);
        if (path.size() > 0) {
            cout << path.size() << '\n';
            for (int i = 0; i < path.size(); i ++) {
                cout << path[i] << ' ';
            }
            return 0;

        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
