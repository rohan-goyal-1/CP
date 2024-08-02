#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

void _solve () {
    int n, x; cin >> n >> x; ++x;
    vector<int> a(n); for (int& i : a) cin >> i;
    vector<int64_t> dp(n + 2, 0), pfx(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pfx[i + 1] = pfx[i] + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        int q = lower_bound(pfx.begin(), pfx.end(), pfx[i] + x) - pfx.begin();
        dp[i] = dp[q] + q - i - 1;
    }

    int64_t ans = accumulate(dp.begin(), dp.end(), (int64_t) 0);
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
