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
    vector<int> dist(n+1, -1);
    vector<int> prev(n+1);
    dist[1] = 1;
    for (int i = 0; i < n; i++) {
        int cur = out[i];
        if (dist[cur] != -1) {
            for (auto neighbour : graph[cur]) {
                if (dist[cur] + 1 > dist[neighbour]) {
                    dist[neighbour] = dist[cur] + 1;
                    prev[neighbour] = cur;
                }
            }
        }
    }
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << dist[n] << '\n';
        vector<int> trip = {n};
        while (trip.back() != 1) {
            trip.push_back(prev[trip.back()]);
        }
        for (int i = trip.size() - 1; i >= 0; i--) {
            cout << trip[i] << ' ' ;
        }
    }
    return 0;
}
