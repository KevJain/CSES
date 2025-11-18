#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (x1 == x2) {
            if (x3 == x1) {
                cout << "TOUCH";
            } else if (x3 > x1) {
                if (y1 < y2) {
                    cout << "RIGHT";
                } else {
                    cout << "LEFT";
                }
            } else {
                if (y1 < y2) {
                    cout << "LEFT";
                } else {
                    cout << "RIGHT";
                }
            }
            cout << '\n';
            continue;
        }
        long double m = 1.0 * (y1 - y2) / (x1 - x2);
        long double b = y1 - m * x1;
        cout << m << ' ' << b << endl;
        if (x1 < x2) {
            if (y3 < m * x3 + b) {
                cout << "RIGHT";
            } else if (y3 > m * x3 + b) {
                cout << "LEFT";
            } else {
                cout << "TOUCH";
            }
        } else {
            if (y3 < m * x3 + b) {
                cout << "LEFT";
            } else if (y3 > m * x3 + b){
                cout << "RIGHT";
            } else {
                cout << "TOUCH";
            }
        }
        cout << '\n';
    }
    return 0;
}
