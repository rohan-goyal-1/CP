#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

void _solve () {
    int n; cin >> n;
    string s; cin >> s;

    int max0 = 0, max1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') max1++;
        else if (i == 0 || s[i - 1] == '1') max0++;
    }

    cout << (max1 > max0 ? "YES" : "NO") << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
