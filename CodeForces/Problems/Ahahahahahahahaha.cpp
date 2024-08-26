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
    int zero = 0, one = 0;
    vector<int> a(n); for (int& i : a) {
        cin >> i;
        if (i) one++;
        else zero++;
    }

    if (zero >= one) {
        cout << zero << '\n';
        for (int i = 0; i < zero; i++) {
            cout << 0 << " \n"[i == zero - 1];
        }
    }
    else {
        int x = one - (one % 2);
        cout << x << '\n';
        for (int i = 0; i < x; i++) {
            cout << 1 << " \n"[i == x - 1];
        }
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
