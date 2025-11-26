#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<bool> seen(n+1);
    vector<bool> temp(n+1);
    vector<pair<int, bool>> stack; // use for dfs, false = first time
    for (int i = 1; i <= n; i++) {
        stack.emplace_back(i, false);
        while (!stack.empty()) {
            auto [cur, status] = stack.back();
            stack.pop_back();
            if (status) {
                seen[cur] = true;
                temp[cur] = false;
            } else {
                if (seen[cur]) continue;
                if (temp[cur]) { // Cycle found, print and return
                    int idx = stack.size() - 1;
                    int count = 2;
                    while (stack[idx].first != cur) {
                        if (stack[idx].second) count++;
                        idx--;
                    }
                    cout << count << '\n';
                    for (; idx < stack.size(); idx++) {
                        if (stack[idx].second) {
                            cout << stack[idx].first << ' ';
                        }
                    }
                    cout << cur;
                    return 0;
                }
                stack.emplace_back(cur, true);
                temp[cur] = true;
                for (auto neighbour : graph[cur]) {
                    stack.emplace_back(neighbour, false);
                }
            }

        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
