#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int pow(int b, int e) {
    int out = 1;
    while (e--) out *= b;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int removed = 0;
        int rounds = 0;
        while (removed + (n-removed) / 2 < k - 1) {
            removed += (n-removed) / 2;
            rounds++;
            cout << removed << endl;
        }
        cout << (pow(2,rounds-1) + 1 + (k-removed-1) * pow(2,rounds)) << '\n';
    }
    return 0;
}
