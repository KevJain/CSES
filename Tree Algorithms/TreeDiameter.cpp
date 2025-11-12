#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

pair<int,int> dfs(int cur, int parent, vector<vector<int>>& tree) {
    int deepest = -1;
    int deepest_node = cur;
    for (auto child : tree[cur]) {
        if (child == parent) continue;
        auto [cand, cand_node] = dfs(child, cur, tree);
        if (cand > deepest) {
            deepest = cand;
            deepest_node = cand_node;
        }
    }
    return {deepest+1, deepest_node};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i = 0; i < n-1;i ++) {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    auto [_s, node] = dfs(1, 0, tree);
    auto [diam, _e] = dfs(node, 0, tree);
    cout << diam;
    return 0;
}
