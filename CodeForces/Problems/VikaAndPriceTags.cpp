#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n; cin >> n;
    vector<int> a(n); for (int& i : a) cin >> i;
    vector<int> b(n); for (int& i : b) cin >> i;

    /*
    3
    2 5 2
    1 3 4
    */
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) continue;
        int t = gcd(a[i], b[i]);
        a[i] /= t; b[i] /= t;
        int x = ((a[i] % 2) ^ 1) + (b[i] % 2);
        if (cur != x && cur != -1) {
            cout << "NO\n";
            return;
        }
        cur = x;
    }

    cout << "YES\n";
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
