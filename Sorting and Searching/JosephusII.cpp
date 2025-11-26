// Use list removals technique: determine index of next element to remove from
// remaining list and then remove it, use a BIT for O(nlog^2(n)) time

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
typedef long long ll;
using namespace std;

const int LIMIT = 2e5;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> tree(LIMIT+1);
    auto query = [&tree] (int idx) {
        int s = 0;
        while (idx) {
            s+=tree[idx];
            idx -= idx&-idx;
        } return s;
    };
    auto update = [&tree] (int idx, int d) {
        while (idx < tree.size()) {
            tree[idx] += d;
            idx += idx & -idx;
        }
    };

    int prev = 0; // prev index in remaining list, 1-indexed
    int remaining = n;
    int nidx = 0; // next rank of element in remaining list
    vector<int> removals;
    for (int i = 0; i < n; i++) {
        nidx = prev + k + 1;
        if (nidx > remaining) {
            nidx -= remaining;
            remaining -= removals.size();
            while (!removals.empty()) {
                int removed = removals.back();
                removals.pop_back();
                update(removed, 1);
            }
            nidx %= remaining;
            if (nidx == 0) nidx = remaining;
        }
        int lo, hi;
        lo = 1;
        hi = n;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (mid - query(mid) < nidx) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        cout << lo << ' ';
        removals.push_back(lo);
        prev = nidx;
    }

    return 0;
}
