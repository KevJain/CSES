#include <iostream>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i<=n; i++) {
        q.push(i);
    }
    bool rem = false;
    while (!q.empty()) {
        if (rem) {
            cout << q.front() << ' ';
        } else {
            q.push(q.front());
        }
        q.pop();
        rem = !rem;
    }
    return 0;
}
