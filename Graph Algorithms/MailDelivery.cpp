#include <iostream>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

void visit(int cur, vector<int>& out, vector<set<int>>&graph) {
    while (!graph[cur].empty()) {
        auto it = graph[cur].begin();
        int neighbour = *it;
        graph[cur].erase(it);
        graph[neighbour].erase(cur);
        visit(neighbour, out, graph);
    }
    out.push_back(cur);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n+1, set<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for (int i = 1; i <=n; i++) {
        if (graph[i].size() % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    vector<int> out;
    visit(1, out, graph);
    if (out.size() < m + 1) {
        cout << "IMPOSSIBLE";
    } else {
        for (auto it = out.rbegin(); it != out.rend(); it++) {
            cout << *it << ' ';
        }
    }
    return 0;
}
