#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

template <typename T>
T ceil_div(T a, T b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

void _solve () {
    int64_t ch, cd; cin >> ch >> cd;
    int64_t mh, md; cin >> mh >> md;
    int64_t k, w, a; cin >> k >> w >> a;

    bool ans = false;
    for (int64_t i = 0; i <= k; i++) {
        int64_t x = w * i + cd, y = a * (k - i) + ch;
        ans |= ceil_div<int64_t>(mh, x) <= ceil_div<int64_t>(y, md); // (w * i + cd, a * i + ch)
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
