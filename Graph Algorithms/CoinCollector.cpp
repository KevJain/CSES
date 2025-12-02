// Combine all SCCs into a singular node
// Then topological sort the resulting DAG
// Perform DP from start to end

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

void visit(int cur, vector<vector<int>>& graph, vector<int>& order, vector<bool>& seen) {
    if (seen[cur]) return;
    seen[cur] = true;
    for (auto child : graph[cur]) {
        visit(child, graph, order, seen);
    }
    order.push_back(cur);
}

void add_root(int cur, int root, vector<vector<int>>& rgraph, vector<int>& component) {
    if (component[cur] != -1) return;
    component[cur] = root;
    for (auto child : rgraph[cur]) {
        add_root(child, root, rgraph, component);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<vector<int>> rgraph(n+1, vector<int>());
    vector<int> coins(n+1);
    for (int i = 0; i < n; i++) cin >> coins[i+1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }
    vector<bool> seen(n+1, false);
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        visit(i, graph, order, seen);
    }

    reverse(order.begin(), order.end());
    vector<int> component(n+1, -1);
    int ncomponents = 0;
    for (int i = 0; i < order.size(); i++) {
        if (component[order[i]] != -1) continue;
        add_root(order[i], ++ncomponents, rgraph, component);
    }
    vector<ll> dag_coins(ncomponents + 1);
    for (int i = 1; i <= n; i++) {
        dag_coins[component[i]] += coins[i];
    }
    vector<ll> dp = dag_coins;
    for (int k = 0; k < order.size(); k++) {
        int i = order[k];
        for (auto j : graph[i]) {
            if (component[j] == component[i]) continue;
            dp[component[j]] = max(dp[component[j]], dag_coins[component[j]] + dp[component[i]]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
