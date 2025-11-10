#include <iostream>
using namespace std;

int main() {
    long long n;
    long long s = 0;
    int x;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        s += x;
    }
    cout << (long long)(n * (n+1) / 2) - s;
}
