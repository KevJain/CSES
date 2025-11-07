#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll try_place(int row, vector<int> placed, vector<string> grid) {
    if (row == 8) {
        return 1;
    }
    int ways = 0;
    for (int col = 0; col < 8; col ++) {
        if (grid[row][col] == '*') {
            continue;
        }
        bool valid = true;
        for (int prow = 0; prow < row; prow++) {
            if (placed[prow] == col ||
                placed[prow] == col + row - prow ||
                placed[prow] == col - row + prow) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;
        placed.push_back(col);
        ways += try_place(row + 1, placed, grid);
        placed.pop_back();
    }
    return ways;
}

int main() {
    vector<string> grid(8, "");
    for (int i = 0; i < 8; i++) {
        cin >> grid[i];
    }
    vector<int> placed = {};
    cout << try_place(0, placed, grid);
    return 0;
}
