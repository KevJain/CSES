#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> seen(n+1);
    int runs = 0;
    int num = 0;
    while (n--) {
        cin >> num;
        if (!seen[num-1]) {
            runs++;
        }
        seen[num] = true;
    }
    cout << runs;
    return 0;
}
