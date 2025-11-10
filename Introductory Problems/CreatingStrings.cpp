#include <iostream>
#include <map>
#include <string>
typedef long long ll;
using namespace std;

void getPerms(string& s, map<char, int> m, int l) {
    if (s.size() == l) {
        cout << s << '\n';
    }
    for (auto& p : m) {
        if (p.second > 0) {
            s += p.first;
            m[p.first]--;
            getPerms(s, m, l);
            m[p.first]++;
            s.erase(s.end()-1);
        }
    }
}

int fact(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fact(n-1);
}

int main() {
    string s;
    char ch;
    int n;
    int l = 0;
    map<char, int> m;
    while (cin >> ch) {
        m[ch]++;
        l++;
    }
    n = fact(l);
    for (auto& p : m) {
        n /= fact(p.second);
    }
    cout << n << '\n';
    getPerms(s, m, l);
    return 0;
}
