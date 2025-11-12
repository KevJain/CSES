#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;


void dfs(int cur, int prev, vector<vector<int> >& tree, vector<int>& e, vector<int>& f) {
    // if we put no edge here, we can either have no edge or an edge at its children
    // if we put an edge here, we have to take no edge for one child and max for others
    int total = 0;
    bool canAdd = false;
    for (auto& child : tree[cur]) {
        if (child == prev) continue;
        dfs(child, cur, tree, e, f);
        total += max(e[child], f[child]);
    }
    f[cur] = total;
    for (auto& child : tree[cur]) {
        if (child == prev) continue;
        e[cur] = max(e[cur], total - max(e[child], f[child]) + f[child] + 1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        if (!(cin >> a >> b)) {
            cout << "error";
        }
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> edge_here(n+1);
    vector<int> free_here(n+1);
    dfs(1, 0, tree, edge_here, free_here);
    cout << max(edge_here[1], free_here[1]);
    return 0;
}
