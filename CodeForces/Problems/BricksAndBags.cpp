#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server

// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structuans

// ** RESET GLOBALS **

void _solve () {
    int n; cin >> n;
    vector<int> a(n); for (int& i : a) cin >> i;

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        ans = max(ans, a[n - 1] - a[i] + a[i + 1] - a[i]);
    }
    for (int i = 2; i < n; i++) {
        ans = max(ans, a[i] - a[0] + a[i] - a[i - 1]);
    }

    cout << ans << '\n';
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
