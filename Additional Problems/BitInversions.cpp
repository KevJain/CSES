#include <iostream>
#include <string>
#include <set>

typedef long long ll;
using namespace std;

int main() {
    // Use two sets to store the state of the array
    // First set stores current intervals, [l,r] of consecutive digits
    // Second set stores interval lengths
    // When we change a digit, look up its current interval and length
    // and update the sets accordingly
    // When splitting intervals, we have following cases for
    // position a in interval [l,r]:
    // 1. a = l = r: Delete this interval and merge left and right
    // 2. a = l < r: shorten current interval, extend left interval
    // 3. l < r = a: symmetric
    // 4. l < a < r: split this interval into 3
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string bits;
    int m;
    getline(cin, bits);
    cin >> m;
    int l = 0;
    set<pair<int,int>> intervals;
    multiset<int> lengths;
    for (int r = 0; r < bits.size(); r++) {
        if (bits[r] != bits[l]) {
            intervals.insert({l+1, r});
            lengths.insert(r-l);
            l = r;
        }
    }
    auto print = [](set<pair<int,int>>& s) {
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << '[' << (it->first) << ' ' << (it->second) << ']';
        }
        cout << endl;
    };
    intervals.insert({l+1, bits.size()});
    lengths.insert(bits.size()-l);
    for (int i = 0; i < m; i ++) {
        int b;
        cin >> b;
        auto interval = prev(intervals.upper_bound({b, 1000000}));
        auto [left, right] = *interval;
        //cout << left << ',' << right << endl;
        //print(intervals);
        if (b == left) {
            if (left == right) { // Case 1
                int new_left, new_right;
                if (interval == intervals.begin()) {
                    new_left = left;
                } else {
                    auto left_interval = prev(interval);
                    new_left = left_interval->first;
                    lengths.erase(lengths.find(left_interval->second - left_interval->first + 1));
                    intervals.erase(left_interval);
                }
                if (next(interval) == intervals.end()) {
                    new_right = right;
                } else {
                    auto right_interval = next(interval);
                    new_right = right_interval->second;
                    lengths.erase(lengths.find(right_interval->second - right_interval->first + 1));
                    intervals.erase(right_interval);
                }
                intervals.insert({new_left, new_right});
                lengths.insert(new_right - new_left + 1);
            } else { // Case 2
                if (interval == intervals.begin()) {
                    intervals.insert({b,b});
                    lengths.insert(1);
                    intervals.insert({b+1, right});
                    lengths.insert(right - left);
                } else {
                    auto left_interval = prev(interval);
                    intervals.insert({left_interval->first, b});
                    lengths.insert(b - left_interval->first + 1);
                    intervals.insert({b + 1, right});
                    lengths.insert(right - left);
                    lengths.erase(lengths.find(left_interval->second-left_interval->first+1));
                    intervals.erase(left_interval);
                }
            }
        } else {
            if (b == right) { // Case 3
                if (next(interval) == intervals.end()) {
                    intervals.insert({b,b});
                    lengths.insert(1);
                    intervals.insert({left, b-1});
                    lengths.insert(right-left);
                } else {
                    auto right_interval = next(interval);
                    intervals.insert({b, right_interval->second});
                    lengths.insert(right_interval->second - b + 1);
                    intervals.insert({left, b-1});
                    lengths.insert(right - left);
                    lengths.erase(lengths.find(right_interval->second-right_interval->first+1));
                    intervals.erase(right_interval);
                }
            } else { // Case 4
                intervals.insert({left, b-1});
                intervals.insert({b, b});
                intervals.insert({b+1, right});
                lengths.insert(b-left);
                lengths.insert(right-b);
                lengths.insert(1);
            }
        }
        lengths.erase(lengths.find(right - left + 1));
        intervals.erase(interval);
        cout << *lengths.rbegin() << ' ';
    }
    //print(intervals);
    return 0;
}
