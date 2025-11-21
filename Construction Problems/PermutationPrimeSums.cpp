// Basic strategy: find the smallest prime larger than n, denoted by p_n
// Then pair the numbers (n - i, p_n - n + i) to all have the sum p_n
// Then we will be left with numbers 1 to p_n - n - 1, solve this subproblem

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

const int PLIMIT = 100033; // 100033 is the smallest prime greater than 1e5
int primes[PLIMIT + 1];
void sieve() {
    for (int i = 2; i <= PLIMIT; i++) {
        if (primes[i] == true) continue;
        for (int m = i + i; m <= PLIMIT; m += i) {
            primes[m] = true;
        }
    }
}

void display(vector<int>& a) {
    for (auto& i : a) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    sieve();
    vector<int> a;
    vector<int> b;
    while (n > 0) {
        int next_p = n + 1;
        while (primes[next_p]) next_p++;
        for (int i = next_p - n; i <= n; i++) {
            a.push_back(i);
            b.push_back(next_p - i);
        }
        n = next_p - n - 1;
    }
    display(a);
    display(b);
    return 0;
}
