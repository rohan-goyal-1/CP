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
    vector<int> a(n); for (int& i : a) cin >> i;

    int idx = 0;
    while (idx < n && a[idx] == 1) idx++;

    int64_t ans = 0;
    int last = 0;
    for (int i = idx + 1; i < n; i++) {
        if (a[i] == 1) {
            cout << -1 << '\n';
            return;
        }
        int cur = 0; int64_t t = a[i];
        while (t < a[i - 1]) {
            t *= t;
            cur++;
        }
        t = a[i - 1];
        while (last > 0 && t * t <= (int64_t) a[i]) {
            t *= t;
            last--;
        }
        cur += last;
        last = cur;
        ans += cur;
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
