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
    int inf = 1e9;
    vector<vector<int>> gridLatest(n, vector<int>(m));
    vector<vector<int>> grid(n, vector<int>(m, -1));
    vector<pair<int,int>> monsters;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                gridLatest[r][c] = inf; // walkable
            } else if (ch == 'A') {
                start = {r, c};
            } else if (ch == 'M') {
                monsters.push_back({r,c});
                gridLatest[r][c] = 0;
            } else {
                gridLatest[r][c] = 0;
            }
        }
    }
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<char> dirChs = {'U','D','L','R'};
    // Do multisource BFS from monster locations to determine last time possible
    // for each cell
    queue<pair<int,int>> q;
    for (auto m : monsters) {
        q.push(m);
    }
    int time = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int j = 0; j < sz; j++) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                auto [dr, dc] = dirs[i];
                int nr = row + dr;
                int nc = col + dc;
                if (0 <= nr && nr < n && 0 <= nc && nc < m &&
                    gridLatest[nr][nc] == inf) {
                    gridLatest[nr][nc] = time;
                    q.push({nr,nc});
                }
            }
        }
        time++;
    }

    q.push(start);
    bool found = false;
    time = 1;
    while (!q.empty() && !found) {
        int sz = q.size();
        for (int j = 0; j < sz; j++) {
            auto [row, col] = q.front();
            q.pop();
            if (row == 0 || row == n-1 || col == 0 || col == m-1) {
                dest = {row, col};
                found = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                auto [dr, dc] = dirs[i];
                int nr = row+dr;
                int nc = col+dc;
                if (0 <= nr < n && 0 <= col < m && gridLatest[nr][nc] > time && grid[nr][nc] == -1) {
                    grid[nr][nc] = i;
                    q.push({nr, nc});
                }
            }

        }
        time++;
    }
    if (!found) {
        cout << "NO";
    } else {
        auto [x,y] = dest;
        string path = "";
        while (!(x == start.first && y == start.second)) {
            path += dirChs[grid[x][y]];
            auto [dx, dy] = dirs[grid[x][y]];
            x -= dx;
            y -= dy;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl << path.size() << endl;
        cout << path;
    }
    return 0;
}
