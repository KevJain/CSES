#include <iostream>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                grid[r][c] = true; // walkable
            }
        }
    }
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    int count = 0;
    for (int r = 0; r < n; r ++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c]) {
                count++;
                queue<pair<int,int>> q;
                q.push({r,c});
                grid[r][c] = false;
                while (!q.empty()) {
                    auto [row, col] = q.front();
                    q.pop();
                    for (auto [dr, dc] : dirs) {
                        int nr = row + dr;
                        int nc = col + dc;
                        if (0 <= nr && nr < n && 0 <= nc && nc < m &&
                            grid[nr][nc]) {
                            grid[nr][nc] = false;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }
    cout << count;
    return 0;
}
