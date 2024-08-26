#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    auto ask = [&] (int a, int b) -> int {
        cout << "? " << a << ' ' << b << endl;
        int s; cin >> s;
        return s;
    };

    int l = 1, r = 999;
    while (r - l > 1) {
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;
        int s = ask(m1, m2);
        if (s == -1) exit(0);
        if (s == m1 * m2) {
            l = m2;
        }
        else if (s == m1 * (m2 + 1)) {
            l = m1;
            r = m2;
        }
        else {
            r = m1;
        }
    }
    cout << "! " << r << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
#ifndef local
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
