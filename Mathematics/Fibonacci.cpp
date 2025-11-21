// ((1,1),(1,0))^n = ((F_{n+1}, F_n), (F_n, F_{n-1}))

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

ll state[4] = {1, 1, 1, 0};

ll*

ll powmod(int state[4], ll exp) {
    auto out = state;
    while (exp) {
        if (exp & 1) {
            ll tmp[4] = 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    return 0;
}
