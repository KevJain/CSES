// Use bitmask dp to represent visited states
#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
ll ways[1<<20][20];
int graph[20][20];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1]++;
    }
    if (n == 2) {
        cout << graph[0][1];
        return 0;
    }
    for (int i = 1; i < n-1; i++) {
        ways[1<<(i-1)][i] += graph[0][i];
    }
    for (int m = 1; m < 1 << (n-2); m++) {
        for (int last = 1; last < n-1; last++) {
            ll w = ways[m][last];
            if (w > 0) {
                for (int k = 1; k < n-1; k++) {
                    if (graph[last][k] && (((m >> (k-1)) & 1) == 0)) {
                        ll & nw = ways[m | (1 << (k-1))][k];
                        nw += w * graph[last][k];
                        nw = nw > mod ? nw % mod : nw;
                    }
                }
            }
        }
    }
    ll out = 0;
    for (int i = 1; i < n-1; i++) {
        out += ways[(1<<(n-2))-1][i] * graph[i][n-1];
        out %= mod;
    }
    cout << out;
    return 0;
}
