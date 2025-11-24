#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> prices(n);
    vector<int> pages(n);
    for (auto &p : prices) {
        cin >> p;
    }
    for (auto &p : pages) {
        cin >> p;
    }
    vector<int> max_pages(target + 1);
    for (int i = 0; i < n; i++) {
        int price = prices[i];
        int page = pages[i];
        for (int j = target; j >= price; j--) {
            max_pages[j] = max(max_pages[j-price] + page, max_pages[j]);
        }
    }
    cout << max_pages[target];
    return 0;
}
