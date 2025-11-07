#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    // Soemthing contains it: start point increasing, max endpoint seen
    // It contains something: endpoint increasing, max startpoint seen
    int n, start, end;
    cin >> n;
    vector<pair<int,int>> intervals(n);
    map<pair<int,int>, int> index;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        intervals[i] = {start, end};
        index[intervals[i]] = i;
    }
    auto cmp1 = [](pair<int,int> a, pair<int,int> b) {
        return a.first < b.first || (a.first == b.first && b.second < a.second);
    };
    auto cmp2 = [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    };
    sort(intervals.begin(), intervals.end(), cmp2);
    vector<int> out(n);
    int mx_start = -1;
    for (auto& p : intervals) {
        if (mx_start >= p.first) {
            out[index[p]] = 1;
        }
        mx_start = max(mx_start, p.first);
    }
    for (auto i : out) {
        cout << i << ' ';
    }
    cout << endl;
    sort(intervals.begin(), intervals.end(), cmp1);
    out.assign(n, 0);
    int mx_end = -1;
    for (auto& p : intervals) {
        if (mx_end >= p.second) {
            out[index[p]] = 1;
        }
        mx_end = max(mx_end, p.second);
    }
    for (auto i : out) {
        cout << i << ' ';
    }

    return 0;
}
