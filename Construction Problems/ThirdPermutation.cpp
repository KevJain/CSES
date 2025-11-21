#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <deque>
typedef long long ll;
using namespace std;

vector<int> tryPlace(deque<int>& pos, vector<int>& a, vector<int>& b) {
    vector<int> out;
    deque<int> buf;
    for (int i = 0; i < a.size(); i++) {
        while (!pos.empty() && (pos.front() == a[i] || pos.front() == b[i])) {
            buf.push_back(pos.front());
            pos.pop_front();
        }
        if (pos.empty()) break;
        else {
            out.push_back(pos.front());
            pos.pop_front();
            while (!buf.empty()) {
                pos.push_back(buf.front());
                buf.pop_front();
            }
        }
    }
    if (out.size() == a.size()) {
        return out;
    }
    return {};
}

void display(vector<int>& v) {
    for (auto& i : v) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    deque<int> pos(n);
    iota(pos.begin(), pos.end(), 1);
    auto out = tryPlace(pos, a, b);
    if (out.size() == n) {
        display(out);
        return 0;
    }
    pos.resize(n);
    iota(pos.rbegin(), pos.rend(), 1);
    out = tryPlace(pos, a, b);
    if (out.size() == n) {
        display(out);
        return 0;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
