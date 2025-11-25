// Bellman Ford

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
typedef long long ll;
using namespace std;
ll ninf = -1e18;
ll inf = 1e18;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,ll>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    vector<ll> score(n+1, ninf);
    score[1] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [a, b, c] : edges) {
            if (score[a] > ninf) {
                score[b] = max(score[b], score[a] + c);
            }
        }
    }
    // Check if we have score-increasing cycle
    for (int i = 0; i < n; i++){
        for (auto [a, b, c] : edges) {
            if (score[a] > ninf && score[b] < score[a] + c) {
                score[b] = inf;
            }
        }
    }
    if (score[n] >= inf) {
        cout << -1;
    } else {
        cout << score[n];
    }
    return 0;
}
