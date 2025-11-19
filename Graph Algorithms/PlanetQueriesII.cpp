#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
typedef long long ll;
using namespace std;

int MAX_K = 18;
int MAX_N = 200000;

void display(vector<int>& v) {
    for (auto& e : v) {
        cout << e << ' ';
    }
    cout << endl;
}

int advance(int start, int steps, vector<vector<int>>& dest) {
    for (int i = 0; i < MAX_K; i++) {
        if (steps >> i & 1) {
            start = dest[i][start];
        }
    }
    return start;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // Need to solve each query in O(logn) with at most O(nlogn) preprocess
    // Idea: There are two types of nodes: those in a cycle and those that lead into a cycle
    // Create an ID for each cycle, then every node can also be tagged
    // with the cycle it leads into and whether or not it is actually in the cycle
    // for nodes not in a cycle, track their distance from the cycle
    // for each cycle, pick a node as the root and for each node in the cycle
    // record their distance to the root
    // Now for query a, b, if a and b do not lead to the same cycle, no path exists
    // Then if b is in the cycle, we know it is reachable
    // if a is in the cycle and b is not, unreachable
    // if a and b are both not in the cycle, if dist(a) < dist(b), unreachable
    // otherwise move a up to match dist(b), if the successor is b itself then return
    // otherwise unreachable

    int n, q;
    cin >> n >> q;
    vector<vector<int>> dest(MAX_K, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        cin >> dest[0][i];
    }
    for (int j = 1; j < MAX_K; j++) {
        for (int i = 1; i <= n; i++) {
            dest[j][i] = dest[j-1][dest[j-1][i]];
        }
    }
    vector<int> in_cycle(n+1, -1); // distance to cycle, 0 = in cycle
    vector<int> dist(n+1, -1); // in cycle: dist to root, out of cycle: dist to cycle
    // note that cycles might have different entry points
    vector<int> root(n+1, -1);

    for (int i = 1; i <= n; i++) {
        if (in_cycle[i] != -1) continue; // already seen
        unordered_set<int> seen_here;
        vector<int> stack;
        int cur = i;
        while (in_cycle[cur] == -1 && seen_here.count(cur) == 0) {
            stack.push_back(cur);
            seen_here.insert(cur);
            cur = dest[0][cur];
        }
        if (in_cycle[cur] != -1) { // found previous computed
            int root_here = root[cur];
            int d_to_root;
            if (root[cur] == cur) {
                d_to_root = 0;
            } else {
                d_to_root = dist[cur];
            }
            int node = 0;
            d_to_root++;
            while (!stack.empty()) {
                node = stack.back();
                stack.pop_back();
                dist[node] = d_to_root;
                root[node] = root[cur];
                in_cycle[node] = in_cycle[dest[0][node]] + 1;
                d_to_root++;
            }
        } else { // new cycle detected
            int d = 1;
            int node;
            int cycle = 0;
            while (!stack.empty()) {
                node = stack.back();
                stack.pop_back();
                dist[node] = d;
                root[node] = cur;
                in_cycle[node] = cycle;
                d++;
                if (cycle) cycle++;
                if (node == cur) {
                    d = 1;
                    cycle = 1;
                }
            }
        }
    }
    //display(in_cycle);
    //display(dist);
    //display(root);
    while (q--) {
        int a,b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << '\n';
        } else if (root[a] != root[b] || in_cycle[a] == 0 && in_cycle[b] > 0) {
            cout << -1 << '\n';
        } else if (in_cycle[a] == 0 && in_cycle[b] == 0) {
            if (dist[a] > dist[b]) {
                cout << (dist[a] - dist[b]) << '\n';
            } else {
                cout << (dist[root[a]] - (dist[b] - dist[a])) << '\n';
            }
        } else if (in_cycle[b] == 0) {
            int cycle_entry = advance(a, in_cycle[a], dest);
            int entry_to_b;
            if (cycle_entry == b) {
                entry_to_b = 0;
            } else if (dist[cycle_entry] > dist[b]) {
                entry_to_b = dist[cycle_entry] - dist[b];
            } else {
                entry_to_b = dist[root[cycle_entry]] - (dist[b] - dist[cycle_entry]);
            }
            cout << (in_cycle[a] + entry_to_b) << '\n';
        } else { // both not in cycle
            if (dist[a] <= dist[b]) {
                cout << -1 << '\n';
            } else {
                if (advance(a, dist[a] - dist[b], dest) == b) {
                    cout << (dist[a] - dist[b]) << '\n';
                } else {
                    cout << -1 << '\n';
                }
            }
        }
    }
    return 0;
}
