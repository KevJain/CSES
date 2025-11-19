#include <iostream>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

void compute_depths(int node, int prev, int depth, set<pair<int,int>>& nodes, vector<vector<int>>& tree, vector<int>& parent) {
    nodes.insert({-depth, node});
    parent[node] = prev;
    for (auto child : tree[node]) {
        if (child == prev) continue;
        compute_depths(child, node, depth+1, nodes, tree, parent);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<vector<int>> tree(n + 1, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<bool> seen(n+1, false);
    set<pair<int,int>> nodes; // depth, id
    vector<int> parent(n+1);
    vector<int> closest(n+1, d+1);
    compute_depths(1, 0, 0, nodes, tree, parent);
    vector<int> offices;
    // at each node, store the distance to descendant chosen node
    // each time we process a node, check d/2 ancestors for closest descendant
    // if all are invalid, all seen on the way up are also invalid
    // and we mark them as inelgibile
    // otherwise take this node and update d ancestors
    while (!nodes.empty()) {
        if (!seen[nodes.begin()->second]) {
            int cand = nodes.begin()->second;
            int ancs = 0;
            int anc = cand;
            bool addable = true;
            while (anc > 0 && 2 * ancs <= d) {
                if (ancs + closest[anc] <= d) {
                    addable = false;
                    break;
                }
                ancs ++;
                anc = parent[anc];
            }
            if (addable) {
                offices.push_back(cand);
                ancs = 1;
                anc = cand;
                while (anc > 0 && ancs <= d) {
                    closest[anc] = ancs;
                    ancs++;
                    anc = parent[anc];
                }
            } else {
                int count = 0;
                anc = cand;
                while (count < ancs) {
                    seen[anc] = true;
                    count++;
                    anc = parent[anc];
                }
            }
        }
        nodes.erase(nodes.begin());
    }
    cout << offices.size() << '\n';
    for (auto o : offices) {
        cout << o << ' ';
    }
    return 0;
}
