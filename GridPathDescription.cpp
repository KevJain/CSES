#include <iostream>
#include <vector>
#include <map>
#include <string>
typedef long long ll;
using namespace std;

const vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
const map<char, int> lookup = {{'U',0},{'D',1},{'L',2},{'R',3}};

bool valid(int row, int col, int dr, int dc, bool visited[7][7]) {
    if (0<=row && row < 7 && 0<=col && col < 7 and !visited[row][col]) {
        // Check if we cut off an unexplored area
        if (dr == 1 && row == 6 && (col + 1) < 7 && !visited[6][col+1]) {
            return false;
        } else if (dc == 1 && col == 6 && row - 1 >= 0 && !visited[row-1][6]) {
            return false;
        }
        return true;
    }
    return false;
}

int count(int step, int row, int col, string& desc, bool visited[7][7]) {
    //cout << row << ' ' << col << endl;
    if (step == 48) {
        if (row == 6 && col == 0) {
            return 1;
        }
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
            return out;
        }
        return 0;
    }
    for (auto [dr, dc] : dirs) {
        int nr = row + dr;
        int nc = col + dc;
        if (valid(nr, nc, dr, dc, visited)) {
            visited[nr][nc] = true;
            out += count(step+1, nr, nc, desc, visited);
            visited[nr][nc] = false;
        }
    }
    return out;
}

int main() {
    string desc;
    cin >> desc;
    bool visited[7][7] = {};
    visited[0][0] = true;
    cout << count(0, 0, 0, desc, visited);
    return 0;
}
