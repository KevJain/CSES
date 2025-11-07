#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

template <typename T>
void print_vec(vector<T>& vec) {
    for (auto& e : vec) {
        cout << e << ' ';
    }
    cout << endl;
}

int main() {
    int n, target;
    int mod = 1e9 + 7;
    cin >> n >> target;
    vector<int> coins(n);
    for (auto &c : coins) {
        cin >> c;
    }
    // combs[j] = # ways to make sum j with currently seen coins only
    vector<int> combs(target + 1);
    combs[0] = 1;
    for (auto coin : coins) {
        for (int j = coin; j <= target; j ++) {
            combs[j] += combs[j-coin];
            combs[j] %= mod;
        }
    }
    /*
    for (auto& v : combs) {
        print_vec(v);
    }
    */
    cout << combs[target];
    return 0;
}
