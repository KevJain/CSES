#include <iostream>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<int> prev(n+1);
    for (int i = 0; i < m; i ++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    prev[1] = -1;
    int dist = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int node = q.front();
            q.pop();
            if (node == n) {
                cout << dist << '\n';
                int cur = node;
                vector<int> path;
                while (cur != -1) {
                    path.push_back(cur);
                    cur = prev[cur];
                }
                for (auto it = path.rbegin(); it != path.rend(); it++) {
                    cout << *it << ' ';
                }
                return 0;
            }
            for (auto neighbour : graph[node]) {
                if (prev[neighbour] == 0) {
                    prev[neighbour] = node;
                    q.push(neighbour);
                }
            }
        }
        dist++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
