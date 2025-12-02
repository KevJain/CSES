#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

void visit(int x, vector<vector<int>>& graph, vector<int>& out) {
    while (graph[x].size() > 0) {
        int y = graph[x].back();
        graph[x].pop_back();
        visit(y, graph, out);
    }
    out.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<int> indeg(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
    for (int i = 2; i < n; i++) {
        if (graph[i].size() == indeg[i]) continue;
        cout << "IMPOSSIBLE";
        return 0;
    }
    if (indeg[1] + 1 != graph[1].size() || graph[n].size() + 1 != indeg[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> out;
    visit(1, graph, out);
    if (out.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    reverse(out.begin(), out.end());
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << ' ';
    }
    return 0;
}
