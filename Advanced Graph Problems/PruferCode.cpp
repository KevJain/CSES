#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> prufer_code(n-2);
    for (auto& p : prufer_code) cin >> p;
    set<int> missing;
    for (int i = 1; i <= n; i++) missing.insert(i);
    for (int i = 0; i < n-2; i++) {
        missing.erase(prufer_code[i]);
    }
    for (int i = 0; i < n-2; i++) {

    }
    return 0;
}
