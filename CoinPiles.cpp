#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int t;
    int a, b;
    int total;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        total = a + b;
        if (total % 3 == 0 && 2 * min(a,b) >= max(a,b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
