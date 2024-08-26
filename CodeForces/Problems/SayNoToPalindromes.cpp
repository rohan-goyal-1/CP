#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    string s; cin >> s;
    string t = "abc";

    vector<vector<int>> pfx(6, vector<int>(n + 1));
    int cur = 0;
    do {
        for (int i = 0; i < n; i++) {
            pfx[cur][i + 1] = pfx[cur][i] + (s[i] != t[i % 3]);
        }
        cur++;
    } while (next_permutation(t.begin(), t.end()));

    while (m--) {
        int l, r; cin >> l >> r;
        int ans = n;
        for (int i = 0; i < 6; i++) {
            ans = min(ans, pfx[i][r] - pfx[i][l - 1]);
        }
        cout << ans << '\n';
    }

    return 0;
}
