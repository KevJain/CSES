#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

void move(int m, int s, int d) {
    if (m == 0) {
        return;
    }
    int buf = 6 - s - d;
    move(m - 1, s, buf);
    cout << s << " " << d << '\n';
    move(m - 1, buf, d);
}

int main() {
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    move(n, 1, 3);
    return 0;
}
