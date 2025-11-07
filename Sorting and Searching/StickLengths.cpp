#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, stick;
    cin >> n;
    vector<int> s;
    for (int i = 0; i < n; i ++) {
        cin >> stick;
        s.push_back(stick);
    }
    sort(s.begin(), s.end());
    int target = s[n/2];
    ll changes = 0;
    for (auto stick : s) {
        changes += abs(target - stick);
    }
    cout << changes;
    return 0;
}
