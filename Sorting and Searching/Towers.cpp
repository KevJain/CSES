#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> towers;
    int k;
    while (n--) {
        cin >> k;
        auto it = upper_bound(towers.begin(), towers.end(), k);
        if (it != towers.end()) {
            *it = k;
        } else {
            towers.push_back(k);
        }
    }
    cout << towers.size();
    return 0;
}
