// Run simultaneous BFS from each node, keeping track of origin at each step
// Also keep track of seen nodes for each original search path
// Stop when we exhaust the BFS or we find a node already seen from same origin
// Time complexity: O(n(m+n)), space complexity: O(n^2 + mn)

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<tuple<int,int,int>> q; // cur node, prev, origin
    vector<vector<int>> time(n+1, vector<int>(n+1,-1));
    for (int i = 1; i <= n; i++) {
        q.push({i, 0, i});
        time[i][i] = 0;
    }
    int t = 1;
    while (!q.empty()) {
        int sz = q.size();
        int min_cycle = 1e9;
        for (int i = 0; i < sz; i++) {
            auto [cur, prev, origin] = q.front();
            q.pop();
            for (auto neighbour : graph[cur]) {
                if (neighbour == prev) continue;
                if (time[origin][neighbour] > 0) {
                    min_cycle = min(min_cycle, time[origin][neighbour] + t);
                }
                time[origin][neighbour] = t;
                q.push({neighbour, cur, origin});
            }
        }
        if (min_cycle != 1e9) {
            cout << min_cycle;
            return 0;
        }
        t++;
    }
    cout << -1; // No cycles
    return 0;
}
