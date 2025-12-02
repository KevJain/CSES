#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

const int BSIZE = 8;
int board[BSIZE][BSIZE];
int row_move[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int col_move[] = {1, 2, 2, 1, -1, -2, -2, -1};

int count_moves(int row, int col) {
    int out = 0;
    for (int i = 0; i < 8; i++) {
        int nr = row + row_move[i];
        int nc = col + col_move[i];
        if (0 <= nr && nr < BSIZE && 0 <= nc && nc < BSIZE && board[nr][nc] == 0) {
            out++;
        }
    }
    return out;
}

bool backtrack(int count, int row, int col) {
    if (count == BSIZE * BSIZE) return true;
    vector<pair<int,int>> moves;
    for (int i = 0; i < 8; i++) {
        int nr = row + row_move[i];
        int nc = col + col_move[i];
        if (0 <= nr && nr < BSIZE && 0 <= nc && nc < BSIZE && board[nr][nc] == 0) {
            int nmoves = count_moves(nr, nc);
            if (nmoves > 0 || count == BSIZE * BSIZE - 1) {
                moves.emplace_back(nmoves, i);
            }
        }
    }
    sort(moves.begin(), moves.end());
    for (auto [nmoves, move] : moves) {
        int nr = row + row_move[move];
        int nc = col + col_move[move];
        board[nr][nc] = count + 1;
        if (backtrack(count + 1, nr, nc)) return true;
        board[nr][nc] = 0;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y;
    cin >> x >> y;
    board[y-1][x-1] = 1;
    backtrack(1, y-1, x-1);
    for (auto& row : board) {
        for (auto col : row) {
            cout << col << ' ';
        }
        cout << '\n';
    }
    return 0;
}
