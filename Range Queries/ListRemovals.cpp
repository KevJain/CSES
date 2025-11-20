// Without segment tree: use fenwick tree to compute # removed elements
// less than current element, then we can determine rank of remaining element
// by original rank - # less than removed, so we can binary search on rank
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

void display(vector<int>& n) {
    for (auto & a : n) cout << a << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++) cin >> nums[i];

    vector<int> tree(n+1);
    auto query = [&tree](int i) {
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i&-i;
        }
        return s;
    };

    auto update = [&tree](int i, int d) {
        while (i < tree.size()) {
            tree[i] += d;
            i += i&-i;
        }
    };
    
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        int lo = q; // position in original list
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int rank = mid - query(mid);
            if (rank >= q) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << nums[lo] << ' ';
        update(lo, 1);
    }

    return 0;
}
