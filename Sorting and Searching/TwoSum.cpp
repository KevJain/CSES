#include <iostream>
#include <string>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    int n, target, num;
    cin >> n >> target;
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (m.count(target - num)) {
            cout << m[target-num] << ' ' << i;
            return 0;
        }
        m[num] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
