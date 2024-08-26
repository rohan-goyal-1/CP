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

    int l = 2, r = 999;
    while (l <= r) {
        int mid = (l + r) / 2;
        int s = ask(mid, mid);
        if (s == -1) exit(0);
        if (s == mid * mid) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << "! " << l << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
