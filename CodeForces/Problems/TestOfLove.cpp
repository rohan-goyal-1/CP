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
    int n, m, k; cin >> n >> m >> k;
    string a; cin >> a;
    vector<int> l;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'L') l.push_back(i);
    }
    l.push_back(n);

    int idx = 0;
    for (int i = -1; i < n; ) {
        if (i + m >= l[idx]) {
            i = l[idx];
        }
        else {
            i += m;
            if (i >= n) {
                cout << "YES" << '\n';
                return;
            }
            while (i < n && i < l[idx]) {
                if (a[i] == 'C' || k == 0) {
                    cout << "NO" << '\n';
                    return;
                }
                else {
                    k--;
                    i++;
                }
            }
        }
        idx++;
    }

    cout << "YES" << '\n';
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
