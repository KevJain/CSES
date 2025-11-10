#include <iostream>
#include <string>
#define ll long long;
using namespace std;

int main() {
    char ch;
    char cur = 'q';
    int max_len, cur_len = 0;
    while (cin >> ch) {
        if (ch != cur) {
            if (cur_len > max_len) {
                max_len = cur_len;
            }
            cur_len = 0;
            cur = ch;
        }
        cur_len += 1;
    }
    if (cur_len > max_len) {
        max_len = cur_len;
    }
    cout << max_len;
    return 0;
}
