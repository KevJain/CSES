#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> team(n+1);
    for (int i = 1; i <= n; i ++) {
        if (team[i] != 0) continue;
        int cur = 1;
        queue<int> friends;
        team[i] = cur;
        friends.push(i);
        while (!friends.empty()) {
            int sz = friends.size();
            int next_team = cur == 1 ? 2 : 1;
            for (int j = 0; j < sz; j++) {
                int f = friends.front();
                friends.pop();
                for (auto nfriend : graph[f]) {
                    if (team[nfriend] == cur) {
                        cout << "IMPOSSIBLE";
                        return 0;
                    } else if (team[nfriend] == 0) {
                        team[nfriend] = next_team;
                        friends.push(nfriend);
                    }
                }
            }
            cur = next_team;
        }
    }
    for (int i = 1; i <= n; i ++) {
        cout << team[i] << ' ';
    }
}
