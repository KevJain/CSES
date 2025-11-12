#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

void solve(int cur, vector<vector<int>>& tree, vector<int>& ans) {
    for (auto& subordinate : tree[cur]) {
        solve(subordinate, tree, ans);
        ans[cur-1] += 1 + ans[subordinate-1];
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    vector<int> subordinates(n);
    solve(1, tree, subordinates);
    for (auto c : subordinates) {
        cout << c << ' ';
    }
    return 0;
}
