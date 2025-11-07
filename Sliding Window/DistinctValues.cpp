#include <iostream>
#include <map>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    map<int, int> count;
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
        count[nums[i]]++;
    }
    cout << count.size() << ' ';
    for (int i = k; i < n; i++) {
        cin >> nums[i];
        count[nums[i]]++;
        if (--count[nums[i-k]] == 0) {
            count.erase(nums[i-k]);
        }
        cout << count.size() << ' ';
    }
    return 0;
}
