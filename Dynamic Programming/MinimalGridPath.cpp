#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
typedef long long ll;
using namespace std;

void solve(vector<string>& grid) {
    int n = grid.size();
    // At each time step, we need to take the minimal letter and keep
    // track of the possible locations that have this letter, this is bfs-esque
    string out(1, grid[0][0]);
    vector<vector<bool>> locs(n, vector<bool>(n));
    locs[0][0] = true; // has minimal element
    for (int i = 1; i < 2*n - 1; i ++) {
        int row, col;
        row = min(n-1, i);
        col = max(0, i-(n-1));
        char minCh = 'Z' + 1;
        while (row >= 0 && col < n) {
            if (row > 0 && locs[row-1][col] || col > 0 && locs[row][col-1]) {
                if (grid[row][col] < minCh) {
                    minCh = grid[row][col];
                }
            }
            row--;
            col++;
        }
        out += minCh;
        row = min(n-1, i);
        col = max(0, i-(n-1));
        while (row >= 0 && col < n) {
            if (row > 0 && locs[row-1][col] && grid[row][col] == minCh ||
                col > 0 && locs[row][col-1] && grid[row][col] == minCh) {
                locs[row][col] = true;
            }
            row--;
            col++;
        }
    }
    cout << out;

}


int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &s : grid) {
        cin >> s;
    }
    solve(grid);
    return 0;
}
