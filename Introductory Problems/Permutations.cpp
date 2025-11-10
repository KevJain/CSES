#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 3 || n == 2) {
        cout << "NO SOLUTION";
    }  else {
        for (int evens = 2; evens <= n; evens += 2) {
            cout << evens << " ";
        }
        for (int odds = 1; odds <= n; odds += 2) {
            cout << odds << " ";
        }
    }
    return 0;
}
