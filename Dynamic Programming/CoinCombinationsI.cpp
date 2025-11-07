#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, target;
    int mod = 1e9 + 7;
    cin >> n >> target;
    vector<int> coins(n);
    for (auto &c : coins) {
        cin >> c;
    }
    vector<ll> ways(target + 1);
    ways[0] = 1;
    for (int i = 0; i <= target; i ++) {
        for (auto c : coins) {
            if (i >= c) {
                ways[i] += ways[i-c];
            }
        }
        ways[i] %= mod;
    }
    cout << ways[target];
    return 0;
}
