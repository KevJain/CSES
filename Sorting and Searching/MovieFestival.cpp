#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> movies;
    int count = 0;
    int prev = 0;
    int start, finish;
    while (n--) {
        cin >> start >> finish;
        movies.push_back({finish, start});
    }
    sort(movies.begin(), movies.end());
    for (auto& [f, s] : movies) {
        if (s >= prev) {
            prev = f;
            count += 1;
        }
    }
    cout << count;
    return 0;
}
