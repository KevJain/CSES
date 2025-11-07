#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n*n; i++) {
        cin >> grid[i/n][i%n];
    }
    vector<int> ways(n);
    ways[0] = 1;
    int mod = 1e9 + 7;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == '*') {
                ways[col] = 0;
            } else if (col > 0) {
                ways[col] += ways[col-1];
                ways[col] %= mod;
            }
        }
    }
    cout << ways[n-1];
    return 0;
}
