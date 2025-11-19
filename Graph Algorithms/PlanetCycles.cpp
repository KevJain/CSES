#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
typedef long long ll;
using namespace std;

int dest[200001];
void compute(int start, vector<int>& ans) {
    int node = start;
    vector<int> stack;
    int d = 1;
    while (ans[node] == 0) {
        stack.push_back(node);
        ans[node] = -d++;
        node = dest[node];
    }
    int cur = -1;
    if (ans[node] < 0) { // node is cycle entry
        int cycle_len = d + ans[node];
        while (cur != node) {
            cur = stack.back();
            stack.pop_back();
            ans[cur] = cycle_len;
        }
    }
    while (!stack.empty()) {
        cur = stack.back();
        stack.pop_back();
        ans[cur] = 1 + ans[dest[cur]];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dest[i];
    }
    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) {
            compute(i, ans);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
