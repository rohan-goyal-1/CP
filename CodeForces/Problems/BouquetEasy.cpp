#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n; int64_t m; cin >> n >> m;
    map<int, int> mp;
    vector<int> a(n); for (int& i : a) cin >> i, mp[i]++;

    int64_t ans = 0;
    for (auto [ai, ci] : mp) {
        ans = max(ans, min(m / ai, (int64_t) ci) * ai);
        if (mp.find(ai + 1) != mp.end()) {
            int ci1 = mp[ai + 1];
            int64_t k1 = min(m / ai, (int64_t) ci);
            int64_t pred = ai * k1;
            ci -= k1;
            int64_t coins = m - pred;
            if (coins >= ai + 1) {
                int64_t k2 = min(coins / (ai + 1), (int64_t) ci1);
                pred += k2 * (ai + 1);
                ci1 -= k2;
                coins = m - pred;
            }
            ans = max(ans, min(m / (ai + 1), (int64_t) ci1));
            pred += min({coins, (int64_t) ci1, k1});
            ans = max(ans, pred);
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
