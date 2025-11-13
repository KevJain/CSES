#include <iostream>
#include <string>
#include <array>
typedef long long ll;
using namespace std;

const int LIMIT = 1e6;

auto countDivisors() {
    array<int,LIMIT+1> count{};
    for (ll a = 1; a * a <= LIMIT; a++) {
        for (ll b = a+1; a * b <= LIMIT; b++) {
            count[a*b] += 2;
        }
        count[a*a]++;
    }
    return count;
}


int main() {
    int n, x;
    cin >> n;
    auto divisors = countDivisors();
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << divisors[x] << '\n';
    }
    return 0;
}
