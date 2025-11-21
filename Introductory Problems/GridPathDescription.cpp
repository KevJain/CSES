#include <iostream>
#include <vector>
#include <map>
#include <string>
typedef long long ll;
using namespace std;

const vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
const map<char, int> lookup = {{'U',0},{'D',1},{'L',2},{'R',3}};

bool valid(int row, int col, int dr, int dc, bool visited[9][9]) {
    if (visited[row][col]) return false;
    if (visited[row+dr][col+dc] && !visited[row+dc][col+dr] && !visited[row-dc][col-dr]) return false;
    return true;
}

int count(int step, int row, int col, string& desc, bool visited[9][9]) {
    //cout << row << ' ' << col << endl;
    if (row == 7 && col == 1) {
        if (step == 48) return 1;
        return 0;
    }
    int out = 0;

    if (desc[step] != '?') {
        auto [dr, dc] = dirs[lookup.at(desc[step])];
        int nr = row + dr;
        int nc = col + dc;
        if (valid(nr, nc, dr, dc, visited)) {
            visited[nr][nc] = true;
            out = count(step+1, nr, nc, desc, visited);
            visited[nr][nc] = false;
        }
    } else {
        for (auto [dr, dc] : dirs) {
            int nr = row + dr;
            int nc = col + dc;
            if (valid(nr, nc, dr, dc, visited)) {
                visited[nr][nc] = true;
                out += count(step+1, nr, nc, desc, visited);
                visited[nr][nc] = false;
            }
        }
    }
    return out;
}

int main() {
    string desc;
    cin >> desc;
    bool visited[9][9] = {};
    for (int i = 0; i < 9; i++) {
        visited[i][0] = true;
        visited[0][i] = true;
        visited[8][i] = true;
        visited[i][8] = true;
    }
    visited[1][1] = true;
    cout << count(0, 1, 1, desc, visited);
    return 0;
}
