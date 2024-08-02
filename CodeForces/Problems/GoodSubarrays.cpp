#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

using namespace std;
using i64 = int64_t;
#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

void _solve () {
    int n; cin >> n;
    vector<int> a(n), pfx(n + 1, 0);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c - '0';
        pfx[i + 1] = pfx[i] + a[i];
    }
    map<int, int> m;
    for (int i = 0; i <= n; i++) m[pfx[i] - i]++;
    i64 ans = 0;
    for (auto [s, t] : m) ans += (i64) t * (t - 1) / 2;
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
