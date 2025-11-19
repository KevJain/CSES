#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

const int MAX_K = 30;
const int MAX_N = 200001;
int dest[MAX_N][MAX_K];
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> dest[i][0];
    }
    for (int j = 1; j < MAX_K; j++) {
        for (int i = 1; i <= n; i++) {
            dest[i][j] = dest[dest[i][j-1]][j-1];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        int b = 0;
        while (1 << b <= k && b < MAX_K) {
            if (k >> b & 1) {
                x = dest[x][b];
            }
            b++;
        }
        cout << x << '\n';
    }
    return 0;
}
