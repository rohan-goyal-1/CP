#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n; cin >> n;
    int64_t ans = 0;
    array<map<int, int>, 4> mp;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        ans += mp[0][x]++ + mp[1][y]++ + mp[2][x + y]++ + mp[3][x - y]++;
    }

    ans *= 2;
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
