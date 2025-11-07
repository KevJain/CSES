#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int,int,int>> customers(n);
    for (int i = 0; i < n; i++) {
        int arrive, depart;
        cin >> arrive >> depart;
        customers[i] = {arrive, depart, i};
    }
    sort(customers.begin(), customers.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> rooms;
    int k = 0;
    queue<int> next_room;
    vector<int> out(n);
    for (auto& [arrive, depart, i] : customers) {
        while (!rooms.empty() && rooms.top().first < arrive) {
            auto [_, room] = rooms.top();
            rooms.pop();
            next_room.push(room);
        }
        int assigned;
        if (!next_room.empty()) {
            assigned = next_room.front();
            next_room.pop();
        } else {
            assigned = ++k;
        }
        out[i] = assigned;
        rooms.push({depart, assigned});
    }
    cout << k << endl;
    for (int i = 0; i < n; i ++) {
        cout << out[i] << ' ';
    }
    return 0;
}
