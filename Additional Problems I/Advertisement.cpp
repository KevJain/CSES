// For each board, try to use this board as the tallest element
// To get width, precompute first element before and after that is strictly smaller

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

void display(vector<int>& v) {
    for (auto a : v) cout << a << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> boards(n);
    for (auto& a : boards) {
        cin >> a;
    }
    vector<int> prev_smaller(n, -1); // index of previous smaller element
    vector<int> next_smaller(n, n);

    vector<int> stack;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && boards[stack.back()] >= boards[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            prev_smaller[i] = stack.back();
        }
        stack.push_back(i);
    }
    stack.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && boards[stack.back()] >= boards[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            next_smaller[i] = stack.back();
        }
        stack.push_back(i);
    }
    //display(boards);
    //display(prev_smaller);
    //display(next_smaller);
    ll out = 0;
    for (int i = 0; i < n; i++) {
        out = max(out, boards[i] * (next_smaller[i] - prev_smaller[i] - 1));
    }
    cout << out;

    return 0;
}
