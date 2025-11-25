#include <iostream>
#include <vector>
#include <string>
#include <tuple>
typedef long long ll;
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    vector<ll> dist(n+1, 0);
    vector<int> pred(n+1, 0);
    for (int i = 0; i < n; i++) {
        for (auto [a, b, c] : edges) {
            if (dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                pred[b] = a;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int slow = pred[i];
        int fast = pred[pred[i]];
        while (slow != fast) {
            slow = pred[slow];
            fast = pred[pred[fast]];
        }
        if (slow == 0) continue;
        vector<int> out = {slow};
        fast = pred[slow];
        while (fast != slow) {
            out.push_back(fast);
            fast = pred[fast];
        }
        cout << "YES" << '\n';
        cout << slow << ' ';
        while (!out.empty()) {
            cout << out.back() << ' ';
            out.pop_back();
        }
        return 0;
    }
    cout << "NO";
    return 0;
}
