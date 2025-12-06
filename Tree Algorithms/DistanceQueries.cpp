#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

void dfs(int node, int parent, int depth, vector<int>& depths, vector<vector<int>>& anc, vector<vector<int>>& tree) {
    depths[node] = depth;
    anc[node][0] = parent;
    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs(child, node, depth + 1, depths, anc, tree);
    }
}

int getAnc(int node, int a, vector<vector<int>>& anc) {
    for (int i = 0; i < 18; i++) {
        if (a >> i & 1) {
            node = anc[node][i];
        }
    }
    return node;
}

void print(vector<int>& v) {
    for (auto& i : v) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<vector<int>> anc(n+1, vector<int>(18)); // anc[i][j] = 2^j anc of i
    vector<int> depths(n+1);
    dfs(1, 0, 0, depths, anc, tree);

    for (int j = 1; j < 18; j++) {
        for (int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    //print(anc[0]);
    //print(depths);

    for (int i = 0; i < q; i ++) {
        int a,b;
        cin >> a >> b;
        if (depths[a] > depths[b]) swap(a,b);
        int raised_b = getAnc(b, depths[b] - depths[a], anc);
        int hi = depths[a];
        int lo = 0;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (getAnc(a, mid, anc) == getAnc(raised_b, mid, anc)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
            //cout << mid << '\n';
        }
        //cout << a << ' ' << b << ' ' << raised_b << ' ' << lo << '\n';
        cout << (2 * lo + depths[b] - depths[raised_b]) << '\n';
    }
    return 0;
}
