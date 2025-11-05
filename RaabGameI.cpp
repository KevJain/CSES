#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

void check(int n, int a, int b) {
    if (n < a + b || (a == 0) != (b == 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int ties = n - a - b;
    for (int i = n; i > 0; i--) {
        cout << i << " ";
    }
    cout << '\n';
    for (int i = n; i > n - ties; i--) {
        cout << i << " ";
    }
    for (int i = a; i > 0; i--) {
        cout << i << " ";
    }
    for (int i = n - ties; i > a; i--) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    int n, a, b;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        cin >> n >> a >> b;
        check(n, a, b);
    }
    return 0;
}
