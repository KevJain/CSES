#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a;
        cin >> a;
        int state = 0;
        int first = false;
        for (int i = 0; i + 1 < n; i++) {
            cin >> a;
            if (i % 2 == 1 && a > 0) first = true;
            int cur = i % 2 == 0 && a > 0;
            state ^= cur;
        }
        cout << (first || state ? "first" : "second") << '\n';
    }
    return 0;
}
