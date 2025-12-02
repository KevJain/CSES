// Process queries in reverse and use DSU

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> edges(n+1, set<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    vector<pair<int,int>> removed;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        removed.emplace_back(a, b);
        edges[a].erase(b);
        edges[b].erase(a);
    }
    vector<int> root(n+1);
    int comp = 0;
    vector<int> out;
    for (int i = 1; i <= n; i++) {
        if (root[i] != 0) continue;
        queue<int> q;
        ++comp;
        root[i] = i;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto neighbour : edges[cur]) {
                if (root[neighbour] != 0) continue;
                root[neighbour] = i;
                q.push(neighbour);
            }
        }
    }

    auto get_root = [&] (auto self, int x) -> int {
        if (root[x] != x) root[x] = self(self, root[x]);
        return root[x];
    };

    out.push_back(comp);
    reverse(removed.begin(), removed.end());
    for (auto [a, b] : removed) {
        int pa = get_root(get_root, a);
        int pb = get_root(get_root, b);
        if (pa != pb) {
            root[pb] = pa;
            comp--;
        }
        out.push_back(comp);
    }
    out.pop_back();
    reverse(out.begin(), out.end());
    for (auto o : out) {
        cout << o << ' ';
    }

    return 0;
}
