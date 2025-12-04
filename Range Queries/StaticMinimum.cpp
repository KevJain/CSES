#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> mins(n, vector<int>(18)); // mins[i][j] = min of arr[i:i+2^j]
    for (int i = 0; i < n; i++) {
        cin >> mins[i][0];
    }
    for (int j = 1; j < 18; j++) {
        for (int i = 0; i < n; i++) {
            if ((1 << j) + i <= n) {
                mins[i][j] = min(mins[i][j-1], mins[i+(1<<(j-1))][j-1]);
            }
        }
    }
    //for (int i = 0; i < n ; i++) cout << mins[i][1] << ' ';
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        int sz = b - a;
        int bit = 0;
        while (1 << (bit+1) < sz) bit++;
        cout << min(mins[a][bit], mins[b-(1<<bit)][bit]) << '\n';
    }
    return 0;
}
