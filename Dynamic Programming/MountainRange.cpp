// Idea: Work from shortest to tallest mountains
// For each mountain, track its taller neighbours, and the taller neighbours
// can have 1 more visit than our current mountain

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<int> getPrevTallest(vector<int>& mountains) {
    vector<int> out(mountains.size());
    vector<int> stack;
    for (int i = 0; i < mountains.size(); i++) {
        while (!stack.empty() && mountains[stack.back()] <= mountains[i]) {
            stack.pop_back();
        }
        if (stack.empty()) {
            out[i] = -1;
        } else {
            out[i] = stack.back();
        }
        stack.push_back(i);
    }
    return out;
}

vector<int> getNextTallest(vector<int>& mountains) {
    reverse(mountains.begin(), mountains.end());
    vector<int> out = getPrevTallest(mountains);
    int n = out.size();
    for (int i = 0; i < n; i ++) {
        out[i] = n - 1 - out[i];
    }
    reverse(out.begin(), out.end());
    reverse(mountains.begin(), mountains.end());
    return out;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> mountains(n);
    for (auto& m : mountains) cin >> m;
    vector<int> pred = getPrevTallest(mountains); // closest taller mountain before
    vector<int> succ = getNextTallest(mountains); // closest taller mountain after
    vector<int> dp(n, 1);
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    auto cmp = [&mountains] (int a, int b) {
        return mountains[a] < mountains[b];
    };
    sort(indices.begin(), indices.end(), cmp);
    int max_seen = 1;
    for (int i : indices) {
        if (pred[i] != -1) {
            dp[pred[i]] = max(dp[pred[i]], dp[i] + 1);
        }
        if (succ[i] != n) {
            dp[succ[i]] = max(dp[succ[i]], dp[i] + 1);
        }
        max_seen = max(max_seen, dp[i]);
    }
    cout << max_seen;
    return 0;
}
