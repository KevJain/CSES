#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

void print(vector<int>& v) {
    for (auto& i : v) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = 1;
            }
        }
    }
    // longest continuous empty line from grid[i][j]
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] > 0) {
                grid[i][j] += grid[i+1][j];
            }
        }
    }
    // Problem has been reduced to advertisement over each row in longest
    int max_rect = 0;
    for (int i = 0; i < n; i++) {
        vector<int> prev_low(m, -1);
        vector<int> next_low(m, m);
        vector<int> stack;
        for (int j = 0; j < m; j++) {
            while (!stack.empty() && grid[i][stack.back()] >= grid[i][j]) {
                stack.pop_back();
            }
            if (!stack.empty()) {
                prev_low[j] = stack.back();
            }
            stack.push_back(j);
        }
        stack.clear();

        for (int j = m - 1; j >= 0; j--) {
            while (!stack.empty() && grid[i][stack.back()] >= grid[i][j]) {
                stack.pop_back();
            }
            if (!stack.empty()) {
                next_low[j] = stack.back();
            }
            stack.push_back(j);
        }
        /*
        print(grid[i]);
        print(next_low);
        print(prev_low);
        cout << endl;
        */
        for (int j = 0; j < m; j++) {
            max_rect = max(max_rect, grid[i][j] * (next_low[j] - prev_low[j] - 1));
        }

    }
    cout << max_rect;

    return 0;
}
