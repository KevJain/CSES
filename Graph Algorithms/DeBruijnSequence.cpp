// Construct a graph between k-bit strings created by appending a bit and removing the first bit
// Then every node has 2 in-edges and 2 out-edges, so an Eulerian path exists.
// if the bit string is bBc, then 1bB 0bB are predecessors, Bc0, Bc1 are successors
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

void visit(int x, vector<vector<int>>& graph, vector<bool>& out) {
    while (!graph[x].empty()) {
        int y = graph[x].back();
        graph[x].pop_back();
        visit(y, graph, out);
    }
    out.push_back(x & 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    n--;
    if (n == 0) {
        cout << 10; return 0;
    }
    vector<vector<int>> graph(1 << n, vector<int>());
    for (int i = 0; i < (1<<n); i++) {
        graph[i>>1].push_back(i);
        graph[(1<<(n-1))|(i>>1)].push_back(i);
    }
    for (int i = 0; i < n; i++) cout << 0;
    vector<bool> out;
    visit(0, graph, out);
    reverse(out.begin(), out.end());
    for (int i = 0; i + 1 < out.size(); i++) {
        cout << out[i];
    }

    return 0;
}
