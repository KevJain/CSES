#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    } else if (n == 4) {
        cout << "2 4 1 3";
        return 0;
    } else if (n < 5) {
        cout << "NO SOLUTION";
        return 0;
    } else if (n == 6) {
        cout << "1 3 5 2 4 6";
        return 0;
    }
    int a, b, c, next, prev;
    a = 1;
    b = 2;
    c = 3;
    next = 4;
    prev = -2;
    while (next < n - 1) {
        if (abs(a - prev) > 1) {
            cout << a << ' ';
            prev = a;
            a = b;
            b = c;
        } else if (abs(b - prev) > 1) {
            cout << b << ' ';
            prev = b;
            b = c;
        } else {
            cout << c << ' ';
            prev = c;
        }
        c = next;
        next++;
    }
    // At this point, 5 numbers remain. Map them as 12345 -> 13524
    //
    cout << a << ' ' << c << ' ' << (c+2) << ' ' << b << ' ' << (c+1);
    return 0;
}
