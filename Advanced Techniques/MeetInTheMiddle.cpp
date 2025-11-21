#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;
ll target;
ll nums[40];
vector<ll> getSums(int start, int end) {
    int sz = end - start;
    vector<ll> out;
    for (int m = 0; m < 1 << sz; m++) {
        //cout << "m = " << m << endl;
        ll s = 0;
        for (int i = 0; i < sz; i++) {
            if (m >> i & 1) s += nums[start+i];
        }
        if (s <= target) out.push_back(s);
        else m += (m & -m) - 1;
    }
    sort(out.begin(), out.end());
    return out;
}

void display(vector<ll>&v){
    for(auto&i:v) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    auto c1 = getSums(0, n/2);
    auto c2 = getSums(n/2, n);
    long long out = 0;
    int l = 0;
    int r = (int)c2.size() - 1;
    while (l < c1.size() && r >= 0) {
        ll l_count = 1;
        while (l + 1 < c1.size() && c1[l] == c1[l+1]) { 
            l_count++;
            l++;
        }
        while (r >= 0 && c1[l] + c2[r] > target) {
            r--;
        }

        if (r >= 0 && c1[l] + c2[r] == target) {
            ll r_count = 1;
            while (r - 1 >= 0 && c2[r] == c2[r-1]) {
                r_count++;
                r--;
            }
            out += l_count * r_count;
        }
        l++;
    }
    cout << out;
    return 0;
}
