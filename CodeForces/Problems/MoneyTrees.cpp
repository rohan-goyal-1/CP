#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

using namespace std;
using i64 = int64_t;
#define eb emplace_back
#define all(x) begin(x), end(x)
#define f first
#define s second

void _solve () {
    int n, k; cin >> n >> k;
    vector<int> a(n), h(n);
    for (int& i : a) cin >> i;
    for (int& i : h) cin >> i;

    int ans = 0;
    int l = 0, r = 0, sum = 0;
    for (; l < n; l++) {
        while (r < n && sum + a[r] <= k && (r <= l || h[r - 1] % h[r] == 0)) sum += a[r], r++;
        ans = max(ans, r - l);
        sum -= a[l];
    }
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
