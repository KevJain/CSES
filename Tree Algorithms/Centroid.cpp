#include <iostream>
#include <string>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

int dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& tree_size) {
    for (int child : tree[node]) {
        if (child == parent) continue;
        tree_size[node] += dfs(child, node, tree, tree_size);
    }
    return ++tree_size[node];
}

int centroid(int node, int parent, vector<vector<int>>& tree, vector<int>& tree_size) {
    for (int child : tree[node]) {
        if (child == parent) continue;
        if (tree_size[child] * 2 + 1 > tree.size()) {
            return centroid(child, node, tree, tree_size);
        }
    }
    return node;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> tree_size(n+1);
    dfs(1, 0, tree, tree_size);
    cout << centroid(1, 0, tree, tree_size);

    return 0;
}
