#include <iostream>
#include <vector>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<pair<int, int>> moves = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    int d = 0;
    q.push({0,0});
    grid[0][0] = 0;
    int qsize = 1;
    while (qsize) {
        while (qsize--) {
            pair<int, int> pos = q.front();
            q.pop();
            for (auto& move : moves) {
                int nr = pos.first + move.first;
                int nc = pos.second + move.second;
                if (0 <= nr && nr < n && 0 <= nc && nc < n &&
                    grid[nr][nc] == -1) {
                    grid[nr][nc] = d + 1;
                    q.push({nr, nc});
                }
            }
        }
        qsize = q.size();
        d++;
    }
    for (auto& row : grid) {
        for (auto& k : row) {
            cout << k << ' ';
        }
        cout << '\n';
    }
    return 0;
}
