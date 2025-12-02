// Maintain priority queue of nodes that do not appear further in the Prufer code
// At each step, the smallest node in the priority queue forms the edge with the next node
// Maintain the last occurrence of each node in the code to add it to the pq once
// it is seen at that index

#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> code(n-2);
    for (auto& p : code) cin >> p;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> last(n+1, -1);
    for (int i = 0; i < code.size(); i++) {
        last[code[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (last[i] == -1) pq.push(i);
    }
    for (int i = 0; i < code.size(); i++) {
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ' << code[i] << '\n';
        if (i == last[code[i]]) pq.push(code[i]);
    }
    // Get the last two elements
    if (pq.size() != 2) {
        cout << "Expected 2 elements remaining, got " << pq.size() << '\n';
    }
    int cur = pq.top();
    pq.pop();
    cout << cur << ' ' << pq.top();
    return 0;
}
