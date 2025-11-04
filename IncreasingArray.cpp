#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    int n;
    int prev;
    int cur;
    ll incs = 0;
    cin >> n;
    cin >> prev;
    for (int i = 0; i < n - 1; ++i) {
        cin >> cur;
        incs += max(0, prev - cur);
        prev = max(prev, cur);
    }
    cout << incs;
}
