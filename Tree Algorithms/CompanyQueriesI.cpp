#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> anc(n+1, vector<int>(18)); // anc[i][k] = 2^k anc of i
    for (int i = 0; i < n - 1; i ++) {
        int boss;
        cin >> boss;
        anc[i+2][0] = boss;
    }

    for (int k = 1; k < 18; k++) {
        for (int i = 1; i <= n; i++) {
            anc[i][k] = anc[anc[i][k-1]][k-1];
        }
    }
    for (int i = 0; i < q; i++) {
        int e, k;
        cin >> e >> k;
        int cur = e;
        for (int j = 0; j < 18; j++) {
            if (k >> j & 1) {
                cur = anc[cur][j];
            }
        }
        if (cur == 0) cout << -1 << '\n';
        else cout << cur << '\n';
    }
    return 0;
}
