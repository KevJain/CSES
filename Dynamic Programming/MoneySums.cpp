#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int limit = 0;
    for (auto &c : coins) {
        cin >> c;
        limit += c;
    }
    vector<vector<bool>> canMake(n+1, vector<bool>(limit+1));
    canMake[0][0] = true;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j < limit + 1; j ++) {
            canMake[i+1][j] = canMake[i+1][j] | canMake[i][j];
            if (j >= coins[i]) {
                canMake[i+1][j] = canMake[i+1][j] | canMake[i][j-coins[i]];
            }
        }
    }
    int count = 0;
    vector<int> out;
    for (int s = 1; s <= limit; s++) {
        if (canMake[n][s]) {
            count++;
            out.push_back(s);
        }
    }
    cout << count << '\n';
    for (auto s : out) {
        cout << s << ' ';
    }
    return 0;
}
