#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> prefix(n+1);
    for (int i = 0; i < n; i ++) {
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
    }
    for (int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n';
    }
    return 0;
}
