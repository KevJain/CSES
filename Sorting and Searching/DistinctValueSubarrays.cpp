#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto & a: arr) {
        cin >> a;
    }
    unordered_set<int> seen;
    int r = 0;
    ll out = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && !seen.count(arr[r])) {
            seen.insert(arr[r]);
            r++;
        }
        out += r - l;
        seen.erase(arr[l]);
    }
    cout << out;
    return 0;
}
