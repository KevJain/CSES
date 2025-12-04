#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

void update(int node, int cand, vector<pair<int,int>>& longest) {
    if (cand >= longest[node].first) {
        longest[node].second = longest[node].first;
        longest[node].first = cand;
    } else if (cand > longest[node].second) {
        longest[node].second = cand;
    }
}

void compute_leaf_dist(int cur, int prev, vector<vector<int>>& tree, vector<pair<int,int>>& longest) {
    for (int child : tree[cur]) {
        if (child == prev) continue;
        compute_leaf_dist(child, cur, tree, longest);
        update(cur, longest[child].first + 1, longest);
    }
}

void compute_dist(int cur, int prev, vector<vector<int>>& tree, vector<pair<int,int>>& longest) {
    int cand = 0;
    if (longest[prev].first == longest[cur].first + 1) {
        cand = longest[prev].second + 1;
    } else {
        cand = longest[prev].first + 1;
    }
    update(cur, cand, longest);
    for (int child : tree[cur]) {
        if (child == prev) continue;
        compute_dist(child, cur, tree, longest);
    }
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
    vector<pair<int,int>> longest(n+1);
    longest[0].first = -1;
    compute_leaf_dist(1, 0, tree, longest);
    compute_dist(1, 0, tree, longest);
    for (int i = 1; i <= n; i ++) {
        cout << longest[i].first << ' ';
    }
    return 0;
}
