#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> projects(n);
    vector<pair<int, ll>> profits = {{0,0}}; // day, max profit
    for (int i = 0; i < n; i++) {
        int start, end, profit;
        cin >> start >> end >> profit;
        projects[i] = {end, start, profit};
    }
    sort(projects.begin(), projects.end());
    for (int i = 0; i < n; i++) {
        pair<int, ll> srch = {get<1>(projects[i]),0};
        auto idx = lower_bound(profits.begin(), profits.end(), srch);
        idx--;
        ll cand = idx->second + get<2>(projects[i]);
        if (cand > profits.back().second) {
            profits.emplace_back(get<0>(projects[i]), cand);
        }
    }
    cout << profits.back().second;
    return 0;
}
