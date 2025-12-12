// There are 9! = 362880 possible boards, we can BFS from the original to get distances
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
typedef long long ll;
using namespace std;

int powers[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
pair<int,int> moves[] = {{0, 1}, {0,3}, {1, 4}, {1, 2}, {2, 5}, {3, 4}, {3, 6}, {4, 5},
{4, 7}, {5, 8}, {6, 7}, {7, 8}};

int _swap(int state, int p1, int p2) {
    // Counts from least significant digit
    int d1 = state / powers[p1] % 10;
    int d2 = state / powers[p2] % 10;
    state += (d2 - d1) * powers[p1];
    state += (d1 - d2) * powers[p2];
    return state;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    unordered_map<int, int> dists;
    int n, d;
    n = 0;
    for (int i = 0; i < 9; i++) {
        cin >> d;
        n = 10 * n + d;
    }
    if (n == 123456789) {
        cout << 0;
        return 0;
    }
    dists[123456789] = 0;
    queue<int> q;
    q.push(123456789);
    int dist = 1;
    
    while (q.size()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int cur_state = q.front();
            q.pop();
            for (auto [p1, p2] : moves) {
                int next_state = _swap(cur_state, p1, p2);
                if (next_state == n) {
                    cout << dist;
                    return 0;
                }
                if (dists.count(next_state) == 0) {
                    dists[next_state] = dist;
                    q.push(next_state);
                }
            }
        }
        dist++;
    }
    return 0;
}
