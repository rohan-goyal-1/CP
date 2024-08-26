#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

const int MXN = 2e5 + 5;
vector<int> ops(MXN);
vector<int> pfx(MXN + 1);

int log3 (int x) {
    int y = 0;
    while (x != 0) {
        x /= 3;
        y++;
    }
    return y;
}

void solve () {
    int l, r; cin >> l >> r;
    int ans = pfx[r + 1] - pfx[l] + ops[l];
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    for (int i = 0; i < MXN; i++) {
        ops[i] = log3(i);
    }
    for (int i = 0; i < MXN; i++) {
        pfx[i + 1] = pfx[i] + ops[i];
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
