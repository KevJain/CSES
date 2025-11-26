#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    //dp[i][l] will be the number of numbers of exactly length i and leading digit l
    //with no repeated adjacent digits
    vector<vector<ll>> dp(20, vector<ll>(10));
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= 19; i++) {
        for (int l = 0; l < 10; l++) {
            for (int pl = 0; pl < 10; pl++) {
                if (l == pl) continue;
                dp[i][l] += dp[i-1][pl];
            }
        }
    }
    auto calc = [&dp] (ll n) -> ll {
        if (n == 0) return 0;
        ll cpy = n;
        vector<int> digits;
        while (cpy) {
            digits.push_back(cpy%10);
            cpy/=10;
        }
        ll out = 1;
        for (int i = 2; i <= digits.size(); i++) out += dp[i][0];
        for (int l = 1; l < digits.back(); l++) out += dp[digits.size()][l];
        int prev_digit = digits.back();
        bool valid = true;
        for (int i = digits.size() - 1; i > 0; i--) {
            for (int l = 0; l < digits[i-1]; l++) {
                if (l == prev_digit) continue;
                out += dp[i][l];
            }
            if (digits[i-1] == prev_digit) {
                break;
            }
            prev_digit = digits[i-1];
        }
        
        return out;
    };
    cout << (calc(b+1) - calc(a));
    return 0;
}
