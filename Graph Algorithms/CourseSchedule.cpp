// Kahn's Algorithm: maintain set of vertices with zero indegree, add one at a time
// Each time a vertex is added, remove all out edges from the graph and update 
// the zero indegree set

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> indeg(n+1);
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indeg[b]++;
        graph[a].push_back(b);
    }
    vector<int> zero_indeg;
    vector<int> out;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            zero_indeg.push_back(i);
        }
    }
    while (!zero_indeg.empty()) {
        int cur = zero_indeg.back();
        zero_indeg.pop_back();
        out.push_back(cur);
        for (auto postreq : graph[cur]) {
            if (--indeg[postreq] == 0) {
                zero_indeg.push_back(postreq);
            }
        }
    }
    if (out.size() == n) {
        for (auto c : out) cout << c << ' ';
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
