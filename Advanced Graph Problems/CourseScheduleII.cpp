// Instead of trying to place the smallest available at the front, we want to
// place the largest available (with outdegree 0) at the back

#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> out;
    vector<int> outdeg(n+1);
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        outdeg[a]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (outdeg[i] == 0) pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        out.push_back(cur);
        for (auto parent : graph[cur]) {
            if (--outdeg[parent] == 0) {
                pq.push(parent);
            }
        }
    }
    for (int i = out.size() - 1; i >= 0; i--) {
        cout << out[i] << ' ';
    }

    return 0;
}
