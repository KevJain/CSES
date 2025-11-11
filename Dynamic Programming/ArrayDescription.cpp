#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <numeric>
typedef long long ll;
using namespace std;

int mod = 1e9 + 7;
void print(vector<ll>& v) {
    for (auto& a : v) {
        cout << a << ' ';
    }
    cout << endl;
    return;
}
// we can use a dp array to avoid recalculating already seen states, try naive first
ll calc(int start, int end, int length, int m) { // start <= end
    //cout << start << ' ' << end << ' ' << length << endl;
    vector<ll> ways(m+2, 0);
    if (start == -1) {
        for (int i = 1; i <= m; i++) {
            ways[i] = 1;
        }
        length--;
    } else {
        ways[start] = 1;
    }
    ll p;
    for (int i = 0; i < length; i ++) {
        p = 0;
        for (int j = 1; j <= m; j++) {
            ll tmp = ways[j];
            ways[j] = p + tmp + ways[j+1];
            ways[j] %= mod;
            p = tmp;
        }
        //print(ways);
    }
    if (end == -1) {
        return accumulate(ways.begin(), ways.end(), 0) % mod;
    }
    return (ways[end-1] + ways[end] + ways[end+1]) % mod;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (auto& a : nums) {
        cin >> a;
    }
    vector<tuple<int, int, int>> runs; // start, end, length, -1 means boundary
    int left = -1; // previous non-zero
    int prev = 0;
    for (int i = 0; i < n; i ++) {
        if (nums[i] != 0) {
            if (left != i - 1) {
                runs.push_back({left, i, i - left - 1});
            }
            left = i;
        }
        if (nums[i] != 0 && prev != 0 && abs(nums[i] - prev) > 1) {
            cout << 0;
            return 0;
        }
        prev = nums[i];
    }
    if (left != n - 1) {
        runs.push_back({left, n, n - left - 1});
    }
    ll out = 1;
    for (auto& run : runs) {
        auto [start, end, length] = run;
        if (start != -1) {
            start = nums[start];
        }
        if (end != n) {
            end = nums[end];
        } else {
            end = -1;
        }
        if (start > end) swap(start, end); // convert from index in nums to value
        out *= calc(start, end, length, m);
        out %= mod;
    }
    cout << out;
    return 0;
}
