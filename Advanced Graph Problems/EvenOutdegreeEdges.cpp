#include <iostream>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

void impossible() {
    cout << "IMPOSSIBLE";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m % 2 == 1) impossible();
    vector<set<int>> graph(n+1, set<int>());
    for (int i = 0 ; i < m; i++) {
        int a, b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    return 0;
}
