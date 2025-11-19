// Prim's: add unseen vertex with lowest cost

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll inf = 1e18;

void heapify(vector<int>& arr, vector<int>& dists) {

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n, vector<<pair<int,int>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    // Begin with vertex 1
    ll cost = 0;
    vector<int> unseen(n-1);
    vector<ll> dists(n+1, inf);
    iota(unseen.begin(), unseen.end(), 2);
    update_dists(1, dists, graph);
    

    return 0;
}
