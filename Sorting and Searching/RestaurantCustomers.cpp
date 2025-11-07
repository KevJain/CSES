#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, arrive, depart;
    cin >> n;
    vector<pair<int,int>> times(2*n);
    for (int i = 0; i < n; i++) {
        cin >> arrive >> depart;
        times[2*i] = {arrive,1};
        times[2*i+1] = {depart,-1};
    }
    sort(times.begin(), times.end());
    int count = 0;
    int max_count = 0;
    for (auto& [t, d] : times) {
        count += d;
        //cout << t << ' ' << d << ' ' << count << endl;
        max_count = max(count, max_count);
    }
    cout << max_count;
    return 0;
}
