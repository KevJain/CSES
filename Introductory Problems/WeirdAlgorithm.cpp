#include <iostream>
using namespace std;

int main() {
	long long x;
    cin >> x;
    cout << x << " ";
    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
        } else {
            x = 3 * x + 1;
        }
        cout << x << " ";
    }
}
