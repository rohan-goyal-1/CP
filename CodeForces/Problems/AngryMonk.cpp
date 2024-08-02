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
//  - Unordered_... data structures

// ** RESET GLOBALS **

void _solve () {
    int n, k; cin >> n >> k;
    vector<int> a(k); for (int& i : a) cin >> i;

    int ans = 0;
    int idx = max_element(begin(a), end(a)) - a.begin();
    for (int i = 0; i < k; i++) {
        if (idx == i) continue;
        ans += a[i] + a[i] - 1;
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
