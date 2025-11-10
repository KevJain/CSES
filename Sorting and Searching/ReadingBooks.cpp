#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> books(n);
    ll s = 0;
    for (auto &a : books) {
        cin >> a;
        s += a;
    }
    for (auto a : books) {
        if (2*a > s) {
            cout << 2 * a;
            return 0;
        }
    }
    cout << s;
    return 0;
}
