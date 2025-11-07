#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

const int MAX_VAL = 1e9;

int dfs(int target, vector<int>& coins, vector<int>& dp) {
    if (dp[target] != MAX_VAL) {
        return dp[target];
    }
    //cout << target << endl;
    int min_ways = MAX_VAL;
    for (auto c : coins) {
        if (c <= target) {
            int smaller = dfs(target - c, coins, dp);
            if (smaller != -1) {
                min_ways = min(min_ways, smaller + 1);
            }
        }
    }
    if (min_ways == MAX_VAL) {
        dp[target] = -1;
    } else {
        dp[target] = min_ways;
    }
    return dp[target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    vector<int> mins(target+1, MAX_VAL);
    for (auto &c : coins) {
        cin >> c;
    }
    mins[0] = 0;
    int out = dfs(target, coins, mins);
    cout << out;
    return 0;
}
