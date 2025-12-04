#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

void do_walk(int node, vector<vector<int>>& tree, vector<int>& walk) {
    walk.push_back(node);
    for (int child : tree[node]) {
        do_walk(child, tree, walk);
        walk.push_back(node);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i = 2; i <= n; i ++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    vector<int> walk;
    do_walk(1, tree, walk);

    vector<vector<int>> mins(2*n-1, vector<int>(19)); // mins[i][j] = min of arr[i:i+2^j]
    vector<int> loc(n+1);
    for (int i = 0; i < 2*n-1; i++) {
        mins[i][0] = walk[i];
        loc[walk[i]] = i;
    }

    for (int j = 1; j < 19; j++) {
        for (int i = 0; i < 2*n-1; i++) {
            if ((1 << j) + i <= 2*n-1) {
                mins[i][j] = min(mins[i][j-1], mins[i+(1<<(j-1))][j-1]);
            }
        }
    }
    /*
    for (int i = 0; i < 2*n-1 ; i++) cout << mins[i][0] << ' ';
    cout << '\n';
    for (int i = 0; i < 2*n-1 ; i++) cout << mins[i][1] << ' ';
    cout << '\n';
    for (int i = 0; i < 2*n-1 ; i++) cout << mins[i][2] << ' ';
    */
    while (q--) {
        int a, b;
        cin >> a >> b;
        int loc_a = loc[a];
        int loc_b = loc[b];
        if (loc_a > loc_b) swap(loc_a, loc_b);
        loc_a;
        int sz = loc_b - loc_a + 1;
        int bit = 0;
        while (1 << (bit+1) < sz) bit++;
        //cout << loc_a << ' ' << loc_b << ' ' << sz << '\n';
        cout << min(mins[loc_a][bit], mins[loc_b-(1<<bit) + 1][bit]) << '\n';
    }

    return 0;
}
