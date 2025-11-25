#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> components;
    vector<bool> seen(n+1);
    int single = 0;
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;
        queue<int> q;
        q.push(i);
        seen[i] = true;
        int csize = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            csize++;
            for (auto neighbour : graph[cur]) {
                if (!seen[neighbour]) {
                    q.push(neighbour);
                    seen[neighbour] = true;
                }
            }
        }
        if (csize == 1) {
            single++;
        } else {
            components.push_back(csize);
        }
    }
    vector<bool> out(n+1);
    for (int i = 0; i <= single; i++) out[i] = true;
    for (auto csize : components) {
        for (int j = n; j >= csize; j--) {
            out[j] = out[j] || out[j-csize];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (out[i] ? 1 : 0);
    }
    return 0;
}
