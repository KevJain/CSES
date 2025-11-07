#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> ways(n+1);
    int mod = 1e9 + 7;
    ways[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int prev = 1; (i - prev >= 0) && (prev <= 6); prev++) {
            ways[i] += ways[i-prev];
        }
        ways[i] %= mod;
    }
    cout << ways[n];
    return 0;
}
