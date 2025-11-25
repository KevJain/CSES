#include <iostream>
#include <string>
#include <set>

typedef long long ll;
using namespace std;

int main() {
    // Use two sets to store the state of the array
    // First set stores current intervals, [l,r] of consecutive digits
    // Second set stores interval lengths
    // When we change a digit, look up its current interval and length
    // and update the sets accordingly
    // When splitting intervals, we have following cases for
    // position a in interval [l,r]:
    // 1. a = l = r: Delete this interval and merge left and right
    // 2. a = l < r: shorten current interval, extend left interval
    // 3. l < r = a: symmetric
    // 4. l < a < r: split this interval into 3
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string bits;
    int m;
    getline(cin, bits);
    int n = bits.size();
    vector<int> diffs = {0};
    multiset<int> lengths = {};
    for (int i = 1; i < n; i++) {
        if (bits[i] != bits[i-1]) {
            lengths.insert(i-diffs.back());
            diffs.push_back(i);
        }
    }
    lengths.insert(n - diffs.back());
    diffs.push_back(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i ++) {
        int b;
        cin >> b;

    }
}
