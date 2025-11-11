#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    pair<int,int> start, dest;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                grid[r][c] = 1; // walkable
            } else if (ch == 'A') {
                start = {r, c};
            } else if (ch == 'B') {
                dest = {r,c};
                grid[r][c] = 1;
            }
        }
    }
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<char> dirChs = {'U','D','L','R'};
    queue<pair<int,int>> q;
    q.push(start);
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            auto [dr, dc] = dirs[i];
            int nr = row + dr;
            int nc = col + dc;
            if (0 <= nr && nr < n && 0 <= nc && nc < m &&
                grid[nr][nc] == 1) {
                grid[nr][nc] = 2 + i;
                if (make_pair(nr,nc) == dest) {
                    break;
                }
                q.push({nr,nc});
            }
        }
    }
    if (grid[dest.first][dest.second] == 1) {
        cout << "NO";
    } else {
        auto [x,y] = dest;
        string path = "";
        while (!(x == start.first && y == start.second)) {
            path += dirChs[grid[x][y]-2];
            auto [dx, dy] = dirs[grid[x][y]-2];
            x -= dx;
            y -= dy;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl << path.size() << endl;
        cout << path;
    }
    return 0;
}
