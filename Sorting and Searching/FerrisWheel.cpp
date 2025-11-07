#include <iostream>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int children[n];
    for (int i = 0; i < n; i ++) {
        cin >> children[i];
    }
    sort(children, children + n);
    int r = n - 1;
    int l = 0;
    int pairs = 0;
    while (l < r) {
        while (r > 0 && children[l] + children[r] > x) {
            r--;
        }   
        if (l < r && children[l] + children[r] <= x) {
            pairs++;
            l++;
            r--;
        }
    }
    cout << n - pairs;
    return 0;
}
