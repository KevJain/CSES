#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s ^= a;
        }
        cout << (s == 0 ? "second" : "first") << '\n';
    }
    
    return 0;
}
