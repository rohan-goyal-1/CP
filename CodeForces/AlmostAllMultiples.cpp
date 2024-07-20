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
    int n, x; cin >> n >> x;
    assert(x <= n);
    if (n % x != 0) {
        cout << "-1\n";
        return;
    }

    vector<int> a(n); iota(begin(a), end(a), 1);
    a[0] = x; a[n - 1] = 1;
    for (int i = x + 1; i <= n; i++) {
        if (i % x == 0 && n % i == 0) {
            a[x - 1] = i;
            x = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }
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
