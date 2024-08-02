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
    string s; cin >> s;
    int n = s.length();
    int ans = 0, a = 0, t = INT32_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a++, ans++;
        }
        else {
            t = min(t, a);
            a = 0;
        }
    }
    t = min(t, a);
    ans -= t;

    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
