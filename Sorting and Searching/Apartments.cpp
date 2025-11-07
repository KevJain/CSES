#include <iostream>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int people[n];
    int apts[m];
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apts[i];
    }
    int count = 0;
    sort(people, people + n);
    sort(apts, apts + m);
    int p = 0;
    int a = 0;
    while (p < n && a < m) {
        if (abs(people[p] - apts[a]) <= k) {
            count++;
            p++;
            a++;
        } else {
            if (people[p] < apts[a]) {
                p++;
            } else {
                a++;
            }
        }
    }
    cout << count;
    return 0;
}
