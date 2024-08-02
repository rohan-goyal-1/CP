#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define set_io(x)                                       \
    freopen((string(x) + ".in").c_str(), "r", stdin);   \
    freopen((string(x) + ".out").c_str(), "w", stdout);

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    set_io("rental");
#endif

    int n, m, r; cin >> n >> m >> r;
    vector<int> c(n); for (int& i : c) cin >> i;
    vector<pair<int, int>> s(m); for (auto& [a, b] : s) cin >> b >> a;
    vector<int> f(r); for (int& i : f) cin >> i;

    sort(rbegin(c), rend(c));
    sort(rbegin(s), rend(s));
    sort(rbegin(f), rend(f));

    vector<int64_t> pfx(n + 1);
    for (int i = 0; i < n; i++) {
        pfx[i + 1] = pfx[i];
        if (i >= r) continue;
        pfx[i + 1] += f[i];
    }

    vector<int64_t> mon(n + 1);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        mon[i + 1] = mon[i];
        if (cur >= m) continue;
        while (c[i] > 0 && cur < m) {
            int use = min(c[i], s[cur].second);
            c[i] -= use;
            s[cur].second -= use;
            mon[i + 1] += use * s[cur].first;
            if (s[cur].second <= 0) cur++;
        }
    }

    int64_t ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, mon[i] + pfx[n - i]);
    }

    cout << ans << '\n';

    return 0;
}
