// DSU with union by size

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    vector<int> size(n+1, 1);
    iota(parent.begin(), parent.end(), 0);
    int components = n;
    int largest = 1;

    auto get_parent = [&](auto&& self, int x) -> int {
        if (parent[x] != x) {
            parent[x] = self(self, parent[x]);
        }
        return parent[x];
    };

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int pa = get_parent(get_parent, a);
        int pb = get_parent(get_parent, b);
        if (pa != pb) {
            components--;
            parent[pb] = pa;
            size[pa] += size[pb];
            if (largest < size[pa]) {
                largest = size[pa];
            }
        }
        cout << components << ' ' << largest << '\n';
    }
    return 0;
}
