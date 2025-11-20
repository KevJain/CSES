#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.emplace_back(a,b);
    }
    multiset<int> ends;
    auto cmp = [] (pair<int,int> p1, pair<int,int> p2) {
        return p1.second < p2.second || p1.second == p2.second && p1.first < p2.first;
    };
    int count = 0;
    sort(movies.begin(), movies.end(), cmp);
    for (int i = 0; i < n; i++) {
        auto it = ends.upper_bound(movies[i].first);
        if (it != ends.begin()) {
            it--;
            ends.erase(it);
        }
        if (ends.size() < k) {
            ends.insert(movies[i].second);
            count++;
        }
    } 
    cout << count;
    return 0;
}
