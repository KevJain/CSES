#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

void print(bool r) {
    cout << (r ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << (x2-x1) << endl;
        cout << x1 << y1 << x2 << y2 << x3 << y3 << x4 << y4; 
        double det = (x2-x1)*(y3-y4) - (x3-x4)*(y2-y1);
        cout << "det " << det << endl;
        if (det == 0) {
            double b1 = ((y1-y2) * 1.0 / (x1-x2)) * x1 + y1;
            double b2 = ((y3-y4) * 1.0 / (x3-x4)) * x3 + y3;
            if (b1 != b2) {
                print(false);
                continue;
            }
            if (min(x1, x2) <= x3 && x3 <= max(x1,x2))
        }
        double s = ((x3-x1)*(y3-y4) - (x3-x4)*(y3-y1)) * 1.0 / det;
        if (s < 0 || s > 1) {
            print(false);
            continue;
        }
        double t = ((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1)) * 1.0 / det;
        if (t < 0 || t > 1) {
            print(false);
            continue;
        }
        print(true);
    }
    return 0;
}
