#include <iostream>
#include <vector>
#include <string>
#include <numeric>
typedef long long ll;
using namespace std;
void print(vector<int>& v) {
    for (auto &a : v) {
        cout << a << ' ';
    }
    cout << endl;
}
void solve(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();
    // if we have a match, we can extend
    vector<vector<int>> d(n+1, vector<int>(m+1,0));
    iota(d[0].begin(), d[0].end(), 0);
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            d[i][0] = i;
            d[i][j] = min(d[i-1][j] + 1, min(d[i][j-1] + 1, d[i-1][j-1] + ((s1[i-1] == s2[j-1]) ? 0 : 1))); // change char
        }
    }
    cout << d[n][m];
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2);
    return 0;
}
