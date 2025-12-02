// Topological sort on reverse graph, then use bitmask dp
// Combine SCCs
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

const int LIMIT = 50001;
using B = bitset<LIMIT>;

void visit(int cur, vector<vector<int>>& graph, vector<int>& tsort, vector<bool>& seen) {
    if (seen[cur]) return;
    for (auto neighbour : graph[cur]) {
        visit(neighbour, graph, tsort, seen);
    }
    tsort.push_back(cur);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, queries;
    cin >> n >> m >> queries;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<int> indeg(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        indeg[a]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    vector<B> reachable(n+1);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        reachable[cur][cur] = true;
        for (auto neighbour : graph[cur]) {
            reachable[neighbour] |= reachable[cur];
            if (--indeg[neighbour] == 0) q.push(neighbour);
        }
    }
    for (int i = 0; i < queries; i++) {
        int a, b;
        cin >> a >> b;
        cout << (reachable[a][b] ? "YES" : "NO") << '\n';
    }
    return 0;
}
