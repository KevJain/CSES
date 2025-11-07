#include <iostream>
#include <map>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,int> prev;
    int max_len = 1;
    int l = 0;
    int k;
    for (int r = 1; r <= n; r ++) {
        cin >> k;
        l = max(l, prev[k]);
        max_len = max(max_len, r - l);
        prev[k] = r;
    }
    cout << max_len;
    return 0;
}
