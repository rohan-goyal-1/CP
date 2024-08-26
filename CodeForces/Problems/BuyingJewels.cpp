#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int64_t n, k; cin >> n >> k;
    if (n == k) {
        cout << "YES\n";
        cout << 1 << '\n';
        cout << 1 << '\n';
    }
    else if (k <= (n + 1) / 2) {
        cout << "YES\n";
        cout << 2 << '\n';
        cout << n - (k - 1) << ' ' << 1 << '\n';
    }
    else {
        cout << "NO\n";
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
