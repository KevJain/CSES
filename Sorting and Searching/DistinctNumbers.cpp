#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    while (n--) {
        cin >> nums[n];
    }
    sort(nums.begin(), nums.end());
    int count = 1;
    for (int i = 1; i < nums.size(); i ++) {
        if (nums[i] != nums[i-1]) {
            count++;
        }
    }
    cout << count;
    return 0;
}
