#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& a : arr) cin >> a;
    vector<int> stack;
    for (int i = 0; i < n; i++) {
        auto idx = lower_bound(stack.begin(), stack.end(), arr[i]);
        if (idx == stack.end()) {
            stack.push_back(arr[i]);
        } else {
           *idx = arr[i];
        }
    }
    cout << stack.size();
    return 0;
}
