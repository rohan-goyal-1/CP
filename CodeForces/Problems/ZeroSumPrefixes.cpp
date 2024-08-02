#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

void _solve () {
    int n; cin >> n;
    vector<int> a(n); for (int& i : a) cin >> i;
    vector<int64_t> p(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    int ans = 0, t = 0;
    map<int64_t, int> m;
    for (int i = n - 1; i >= 0; i--) {
        m[p[i + 1]]++;
        t = max(t, m[p[i + 1]]);
        if (a[i] == 0) {
            ans += t;
            m.clear();
            t = 0;
        }
    }
    ans += m[0];
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
