#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> col_seen(n, vector<bool>(2 * n, false));
    vector<bool> row_seen;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int row = 0; row < n; row++) {
        row_seen = vector<bool>(2*n, false);
        for (int col = 0; col < row; col ++) {
            cout << grid[col][row] << ' ';
            row_seen[grid[col][row]] = true;
        }
        cout << 0 << " ";
        for (int col = row + 1; col < n; col++) {
            int i = 1;
            while (col_seen[col][i] || row_seen[i]) {
                i++;
            }
            cout << i << " ";
            grid[row][col] = i;
            col_seen[col][i] = true;
            row_seen[i] = true;
        }
        cout << '\n';
    }
    return 0;
}
