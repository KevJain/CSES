#include <iostream>
#include <vector>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<ll,ll,ll>> projects(n);
    for (int i = 0; i < n; i++) {
        ll a,b,p;
        cin >> a >> b >> p;
        projects.push_back({a,b,p});
    }
    sort(projects.start(), projects.end())
    return 0;
}
