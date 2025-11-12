#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
typedef long long ll;
using namespace std;
//#pragma GCC target("popcnt")


bitset<3000> grid[3000];

int main() {
    int n;
    scanf("%d", &n);
    char s[3001];
    for (int i = 0; i < n; i++) {
        scanf("%s", &s);
        grid[i] = bitset<3000>(s);
    }
    ll total = 0;
    ll count;
    for (int r1 = 0; r1 < n-1; r1++) {
        for (int r2 = r1 + 1; r2 < n; r2++) {
            count = (grid[r1]&grid[r2]).count();
            total += count * (count-1);
        }
    }
    printf("%lld", total >> 1);
    return 0;
}
