#include <iostream>
#include <string>
#include <unordered_map>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> count;
    while (n--) {
        int num;
        cin >> num;
        count[num]++;
    }
    ll mod = 1e9 + 7;
    ll out = 1;
    for (auto [_, v] : count) {
        out *= v + 1;
        out %= mod;
    }
    cout << (out - 1 + mod) % mod;
    return 0;
}
