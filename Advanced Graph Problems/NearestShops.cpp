// Do multisource BFS from each shop city, recording closest and second closest
// for each city, then for each anime shop city poll the neighbours for second closest
// to avoid going backwards, track city of origin along with distance

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> shops(k);
    for (auto& s : shops) cin >> s;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<pair<int,int>> closest(n+1); // distance, city of origin
    vector<pair<int,int>> second_closest(n+1); // distance, city of origin
    vector<pair<int,int>> q; // current city, city of origin
    for (int i = 0; i < k; i++) q.emplace_back(shops[i], shops[i]);
    int d = 0;
    while (!q.empty()) {
        vector<pair<int,int>> new_q;
        while (!q.empty()) {
            auto [cur, origin] = q.back();
            q.pop_back();
            if (closest[cur].second == origin || second_closest[cur].second != 0) continue;
            if (closest[cur].second == 0) {
                closest[cur].first = d;
                closest[cur].second = origin;
            } else {
                second_closest[cur].first = d;
                second_closest[cur].second = origin;
            }
            for (auto neighbour : graph[cur]) {
                new_q.emplace_back(neighbour, origin);
            }
        }
        swap(q,new_q);
        d++;
    }
    for (int i = 1; i <= n; i++) {
        if (closest[i].second == 0 || closest[i].second == i && second_closest[i].second == 0) {
            cout << -1 << ' ';
            continue;
        } else if (closest[i].second == i) {
            cout << second_closest[i].first << ' ';
        } else {
            cout << closest[i].first << ' ' ;
        }
    }
    return 0;
}
