// Use the Floyd-Warshall algorithm to determine all pairs shortest distance

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;// graph[i][v] = shortest distance
    vector<vector<ll>> graph(n+1, vector<ll>(n+1, inf));
    for (int i = 1; i <= n; i ++) graph[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = graph[a][b];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                graph[j][i] = graph[i][j];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] == inf) {
            cout << -1 << '\n';
        } else {
            cout << graph[a][b] << '\n';
        }
    }
    return 0;
}
