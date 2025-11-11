#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

void solve(vector<int>& v1, vector<int>& v2) {
    int n = v1.size();
    int m = v2.size();
    vector<vector<int>> lcs(n+1, vector<int>());
    for (int i = 0; i < m; i ++) {
        vector<int> prev = {};
        for (int j = 0; j < n; j++) { // try to match v1[j]
            vector<int> new_prev = lcs[j+1];
            if (v1[j] == v2[i]) {
                lcs[j+1] = prev;
                lcs[j+1].push_back(v1[j]);
            } else {
                if (lcs[j].size() > lcs[j+1].size()) {
                    lcs[j+1] = lcs[j];
                }
            }
            prev = new_prev;
        }
    }
    cout << lcs[n].size() << endl;
    for (int i = 0; i < lcs[n].size(); i ++) {
        cout << lcs[n][i] << ' ';
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    for (auto& a : v1) {
        cin >> a;
    }
    for (auto& a: v2) {
        cin >> a;
    }
    solve(v1, v2);
    return 0;
}
