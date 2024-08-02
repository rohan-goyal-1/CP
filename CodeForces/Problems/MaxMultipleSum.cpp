#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) begin(x), end(x)
#pragma GCC optimize("O3,unroll-loops")

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100 
#endif

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server

// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

void solve () {
    int n; cin >> n;
    int m = -1, ret = 2;
    for (int x = 2; x <= n; x++) {
        int sum = 0;
        int t = x;
        while (t <= n) {
            sum += t;
            t += x;
        }
        if (sum > m) {
            ret = x;
            m = sum;
        }
    }
    cout << ret << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
