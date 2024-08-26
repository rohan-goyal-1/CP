#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n, x; cin >> n >> x;
    int64_t ans = 0;
    for (int a = 1; a <= x; a++) {
        for (int b = 1; a + b <= x && a * b <= n; b++) {
            // c(a + b) <= n
            ans += min((n - a * b) / (a + b), x - a - b);
        }
    }
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
