#define PROB_NAME "homework"

#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    freopen((string(PROB_NAME) + ".in").c_str(), "r", stdin);
    freopen((string(PROB_NAME) + ".out").c_str(), "w", stdout);
#endif // LOCAL

    int n; cin >> n;
    vector<int64_t> h(n); for (auto& i : h) cin >> i;

    vector<int64_t> mn(n + 1, INT32_MAX), sfx(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        mn[i] = min(mn[i + 1], h[i]);
        sfx[i] = sfx[i + 1] + h[i];
    }
    int64_t s = 0, t = 1;
    for (int i = 0; i < n - 2; i++) {
        if ((sfx[i] - mn[i]) * t > s * (n - 2 - i)) {
            s = sfx[i] - mn[i];
            t = n - 2 - i;
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if ((sfx[i] - mn[i]) * t == s * (n - 2 - i)) {
            cout << i << '\n';
        }
    }

    return 0;
}
