// Very interesting problem. Solve 2-SAT by converting each clause into implicative form
// i.e. (x OR y) == (!x => y) == (!y => x), which allows us to create a graph on the node x, !x, y, !y
// Then check SCCs, if any x, !x are in the same SCC, no assignment exists
// Otherwise, every node in the SCC has the same value, so from topological ordering of condensation
// assign first component to be true, and resolve all downstream implications

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;

int get_term() {
    char sign;
    int val;
    cin >> sign >> val;
    return sign == '+' ? val : -val;
}

void get_ordering(int node, int sz, map<int, vector<int>>& graph, vector<bool>& seen, vector<int>& order) {
    if (seen[node + sz]) return;
    seen[node + sz] = true;
    for (int child : graph[node]) {
        get_ordering(child, sz, graph, seen, order);
    }
    order.push_back(node);
}

void assign_root(int node, int root, map<int, int>& roots, map<int, vector<int>>& rgraph, map<int, vector<int>>& components) {
    if (roots[node] != 0) return;
    roots[node] = root;
    components[root].push_back(node);
    for (int child : rgraph[node]) {
        assign_root(child, root, roots, rgraph, components);
    }
}

void assign(int node, vector<int>& assignment, map<int, vector<int>>& graph) {
    if (assignment[abs(node)] != 0) return;
    assignment[abs(node)] = node > 0 ? 1 : -1;
    for (int child : graph[node]) {
        assign(child, assignment, graph);
    }
}

void impossible() {
    cout << "IMPOSSIBLE";
    exit(0);
}

bool check_assignment(vector<int>& assignment, vector<pair<int,int>>& terms) {
    for (auto [t1, t2] : terms) {
        if (!(assignment[abs(t1)] * abs(t1) == t1) &&
            !(assignment[abs(t2)] * abs(t2) == t2)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> graph; // adjacency list
    map<int, vector<int>> rgraph;
    vector<pair<int,int>> terms;
    for (int i = 0; i < n; i++) {
        int t1 = get_term();
        int t2 = get_term();
        terms.push_back({t1, t2});
        graph[-t1].push_back(t2);
        graph[-t2].push_back(t1);
        rgraph[t2].push_back(-t1);
        rgraph[t1].push_back(-t2);
    }

    vector<int> order;
    vector<bool> seen(2 * m + 1);
    for (int i = -m; i <= m; i++) {
        if (i == 0) continue;
        get_ordering(i, m, graph, seen, order);
    }
    reverse(order.begin(), order.end());
    map<int, int> roots;
    map<int, vector<int>> components;
    for (int node : order) {
        assign_root(node, node, roots, rgraph, components);
    }
    for (int i = 1; i <= m; i++) {
        if (roots[i] == roots[-i]) impossible();
    }
    vector<int> assignment(m+1);
    reverse(order.begin(), order.end());
    for (int node : order) {
        if (assignment[abs(node)] != 0) continue;
        for (int start : components[roots[node]]) {
            assign(start, assignment, graph);
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << (assignment[i] > 0 ? '+' : '-') << ' ';
    }

    return 0;
}
