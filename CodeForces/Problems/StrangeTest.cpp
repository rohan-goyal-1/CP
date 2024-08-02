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
#define rall(x) rbegin(x), rend(x)

void _solve () {
    int a, b; cin >> a >> b;
    assert(a < b);
    int ans = b - a;
    int n = a;
    while (n <= b) {
        int x = n - a;
        for (int i = 0; i <= b - a; i++) {
            ans = min(ans, x + i + 1 + ((a + x) | (b + i)) - (b + i));
        }
        n = (n | (n - 1)) + 1;
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
