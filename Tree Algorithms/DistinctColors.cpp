#include <iostream>
#include <string>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

set<int> dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& color, vector<int>& out) {
    set<int> here = {color[node]};
    for (int child : tree[node]) {
        if (child == parent) continue;
        auto res = dfs(child, node, tree, color, out);
        if (here.size() < res.size()) swap(here, res);
        here.merge(res);
    }
    out[node] = here.size();
    return here;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1, vector<int>());
    vector<int> color(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> out(n+1);
    dfs(1, 0, tree, color, out);
    for (int i = 1; i <= n; i++) {
        cout << out[i] << ' ';
    }
    return 0;
}
