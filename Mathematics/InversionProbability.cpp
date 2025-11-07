#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <iomanip>
typedef long long ll;
using namespace std;

class Fraction {
private:
    ll num;
    ll denom;

    void reduce() {
        ll g = gcd(num, denom);
        num /= g;
        denom /= g;
    }

public:
    ll getNum() {return num;}
    ll getDenom() {return denom;}

    Fraction(ll n = 0, ll d = 1) : num(n), denom(d) {
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.denom + other.num * denom, denom * other.denom);
    }
    Fraction operator*(const Fraction& other) const {
        return (Fraction(num * other.num, denom * other.denom));
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        return os << f.num << '/' << f.denom;
    }
};

const int MAX_NUM = 101;

int main() {
    int n;
    cin >> n;
    Fraction out;
    vector<int> r(n);
    for (int i = 0; i < n; i ++) {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (r[i] <= r[j]) {
                out = out + Fraction(r[i] - 1, 2*r[j]);
            } else {
                out = out + Fraction(2 * r[i] - r[j] - 1, 2 * r[i]);
            }
        }
    }
    cout << out << endl;
    cout << fixed << setprecision(6) << (double)(out.getNum()) / out.getDenom();
    return 0;
}
