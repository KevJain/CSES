#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

void dfs1(int node, int parent, vector<vector<int>>& tree, vector<int>& nchildren, vector<ll>& dists) {
    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs1(child, node, tree, nchildren, dists);
        nchildren[node] += nchildren[child] + 1;
        dists[node] += dists[child] + nchildren[child] + 1;
    }
}

void dfs2(int node, int parent, vector<vector<int>>& tree, vector<int>& nchildren, vector<int>& nanc, vector<ll>& dists) {
    for (int child : tree[node]) {
        if (child == parent) continue;
        nanc[child] = nanc[node] + nchildren[node] - nchildren[child];
        dists[child] = dists[node] + nanc[child] - nchildren[child] - 1;
        dfs2(child, node, tree, nchildren, nanc, dists);
    }
}

void print(vector<int>& v) {
    for (auto & i : v) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> nchildren(n+1);
    vector<ll> dists(n+1);
    dfs1(1, 0, tree, nchildren, dists);
    vector<int> nanc(n+1);
    dfs2(1, 0, tree, nchildren, nanc, dists);
    for (int i = 1; i <= n; i ++) {
        cout << dists[i] << ' ';
    }
    return 0;
}
