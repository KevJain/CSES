#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

void gray(string& s, int p) {
    if (p < 0) {
        cout << s << endl;
        return;
    }
    gray(s, p-1);
    if (s[p] == '0') s[p] = '1';
    else s[p] = '0';
    gray(s, p-1);
}

int main() {
    int n;
    cin >> n;
    string s(n, '0');
    gray(s, n-1);
    return 0;
}
