#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = 2 * (((a > c) + (b > d) > (a < c) + (b < d)) + ((a > d) + (b > c) > (a < d) + (b < c))) ;
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
