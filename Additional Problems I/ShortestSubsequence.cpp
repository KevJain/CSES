// Take the latest possible character

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    string shortest = "";
    char chars[4] = {'A', 'C', 'G', 'T'};
    map<char, vector<int>> locs;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        locs[s[i]].push_back(i+1);
    }
    for (char c : chars) {
        locs[c].push_back(n+1);
    }
    int cur = 0;
    while (cur != n+1) {
        int furthest = 0;
        char furthest_c = '_';
        for (char c : chars) {
            int dist = *upper_bound(locs[c].begin(), locs[c].end(), cur);
            if (dist > furthest) {
                furthest = dist;
                furthest_c = c;
            }
        }
        cur = furthest;
        shortest += furthest_c;
    }
    cout << shortest;
    return 0;
}
