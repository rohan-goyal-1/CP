#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void _solve () {
    int n, m, x, y, d; cin >> n >> m >> x >> y >> d;
    bool ans = (x - d > 1 && d + y < m) || (y - d > 1 && d + x < n);
    cout << (ans ? n + m - 2 : -1) << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
