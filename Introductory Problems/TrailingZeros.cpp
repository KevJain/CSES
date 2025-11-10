#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int out = 0;
    int b = 5;
    while (b <= n) {
        out += (n / b);
        b *= 5;
    }
    cout << out;
    return 0;
}
