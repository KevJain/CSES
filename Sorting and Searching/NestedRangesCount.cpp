#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

class BIT {
private:
    int n;
    vector<int> data;

public:
    BIT(int n) : n(n), data(n + 1) {}

    int query(int m) {
        int out = 0;
        while (m) {
            out += data[m];
            m -= m & (-m);
        }
        return out;
    }
    void add(int m) {
        while (m <= n) {
            data[m]++;
            m += m & (-m);
        }
    }
};

map<int, int> getRankLookup(vector<int>& a) {
    sort(a.begin(), a.end());
    int rank = 0;
    int prev = -1;
    map<int,int> m;
    for (auto v : a) {
        if (v != prev) {
            rank++;
            m[v] = rank;
        }
    }
    return m;
}

int main() {
    // Soemthing contains it: start point increasing, max endpoint seen
    // It contains something: endpoint increasing, max startpoint seen
    int n, start, end;
    cin >> n;
    auto cmp1 = [](pair<int,int> a, pair<int,int> b) {
        return a.first < b.first || (a.first == b.first && b.second < a.second);
    };
    auto cmp2 = [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    };
    vector<pair<int,int>> intervals(n);
    map<pair<int,int>, int> index;
    vector<int> start_vals(n); // For BIT coordinate compression
    vector<int> end_vals(n);
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        intervals[i] = {start, end};
        start_vals[i] = start;
        end_vals[i] = end;
        index[intervals[i]] = i;
    }
    map<int, int> start_ranks = getRankLookup(start_vals);
    map<int, int> end_ranks = getRankLookup(end_vals);
    sort(intervals.begin(), intervals.end(), cmp2);
    vector<int> out(n);
    multiset<int> starts;
    BIT starts_(n);
    for (int i = 0; i < n; i ++) {
        //cout << p.first << p.second << endl;
        /*
        auto s = starts.lower_bound(p.first);
        out[index[p]] = distance(s, starts.end());
        starts.insert(p.first);
        */
        int int_start = start_ranks[intervals[i].first];
        int lt = starts_.query(int_start - 1);
        out[index[intervals[i]]] = i - lt;
        starts_.add(int_start);
    }
    for (auto i : out) {
        cout << i << ' ';
    }
    cout << endl;
    sort(intervals.begin(), intervals.end(), cmp1);
    out.assign(n, 0);
    multiset<int> ends;
    BIT ends_(n);
    for (int i = 0; i < n; i ++) {
        int int_end = end_ranks[intervals[i].second];
        int lt = ends_.query(int_end - 1);
        out[index[intervals[i]]] = i - lt;
        ends_.add(int_end);
        /*
        auto e = ends.lower_bound(p.second);
        out[index[p]] = distance(e, ends.end());
        ends.insert(p.second);
        */
    }
    for (auto i : out) {
        cout << i << ' ';
    }

    return 0;
}
