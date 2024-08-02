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
    vector<int> a(n); for (int& i : a) cin >> i;

    // 6 4
    // 2 3 6 2 1 2
    int ans = 0;
    set<int> s; s.insert(x);
    for (int i = 0; i < n; i++) {
        for (int j : s) {
            if (j % a[i] != 0) continue;
            if (j == a[i]) {
                ans++;
                s = {x, x / a[i]};
                break;
            }
            s.insert(j / a[i]);
        }
    }

    cout << ++ans << '\n';
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
