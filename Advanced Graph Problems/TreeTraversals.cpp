#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    vector<int> loc_pre(n+1);
    vector<int> loc_in(n+1);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
        loc_pre[preorder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        loc_in[inorder[i]] = i;
    }
    auto postorder = [&](auto self, int l, int r, int root) {
        if (l > r) {
            return;
        }
        int lsize = loc_in[root] - l ;
        if (lsize > 0) {
            int lroot = preorder[loc_pre[root] + 1];
            self(self, l, loc_in[root] - 1, lroot);
        }
        if (r - loc_in[root] > 0) {
            int rroot = preorder[loc_pre[root] + 1 + lsize];
            self(self, loc_in[root] + 1, r, rroot);
        }

        cout << root << ' ';
    };

    postorder(postorder, 0, n-1, preorder[0]);
    return 0;
}
