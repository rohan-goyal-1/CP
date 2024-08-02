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
    int ans = a[0];
    for (int i = 1; i < n - 2; i++) {
        if (a[i] && a[i + 1] && a[i + 2]) ans++, i += 2;
    }

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
