#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x;
    cin >> x >> n;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        pq.push(-s);
    }
    ll cost = 0;
    while (pq.size() > 1) {
        ll new_stick = 0;
        new_stick -= pq.top();
        pq.pop();
        new_stick -= pq.top();
        pq.pop();
        cost += new_stick;
        pq.push(-new_stick);
    }
    cout << cost;
    return 0;
}
