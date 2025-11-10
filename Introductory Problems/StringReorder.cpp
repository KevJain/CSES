#include <iostream>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    int s = 0;
    int count[26] = {};
    char ch;
    while (cin >> ch) {
        count[ch - 'A'] += 1;
        s += 1;
    }
    if (*max_element(count, count + 26) > s - s / 2) {
        cout << -1;
        return 0;
    }
    char prev = '!';
    int remaining;
    for (int i = 0; i < s; i ++) {
        remaining = s - i;
        int* max_elem = max_element(count, count + 26);
        if (remaining % 2 == 1 and *max_elem > remaining / 2) {
            //cout << max_elem << ' ' << count << endl;
            prev = (char)('A' + (max_elem - count) );
        } else {
            int j = 0;
            while (count[j] == 0 || (char)('A' + j) == prev) {
                j++;
            }
            prev = 'A' + j;
        }
        count[prev - 'A']--;
        cout << prev;
    }
    return 0;
}
