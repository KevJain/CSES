#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int lo = 1;
    int hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << mid << endl;
        string res;
        cin >> res;
        if (res == "YES") {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << "! " << lo << endl;
    return 0;
}
