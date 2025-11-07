#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i ++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    ll cur = 0;
    for (auto c : coins) {
        if (cur + 1 < c) {
            break;
        }
        cur += c;
    }
    cout << cur + 1;
    return 0;
}
