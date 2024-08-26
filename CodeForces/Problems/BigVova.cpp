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
    vector<int> b, used(n, 0);
    int last = 0;
    for (int i = 0; i < n; i++) {
        int idx = i, best = -1;
        for (int j = 0; j < n; j++) if (!used[j]) {
            if (gcd(last, a[j]) > best) {
                best = gcd(last, a[j]);
                idx = j;
            }
        }
        used[idx] = true;
        last = best;
        b.emplace_back(a[idx]);
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
    }
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
