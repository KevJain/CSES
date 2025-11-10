#include <vector>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int m, n;
    char chars[] = {'A', 'B', 'C', 'D'};
    cin >> m >> n;
    vector<string> grid(m, "");
    for (int i = 0; i < m; i ++) {
        cin >> grid[i];
    }
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            for (int ch = 'A'; ch <= 'D'; ch++) {
                if (grid[row][col] == ch ||
                    (row > 0) && (grid[row-1][col] == ch) ||
                    (col > 0) && (grid[row][col-1] == ch)) {
                    continue;
                }
                grid[row][col] = ch;
                break;
            }
        }
    }
    for (int i = 0; i < m; i ++) {
        cout << grid[i] << '\n';
    }
    return 0;
}
