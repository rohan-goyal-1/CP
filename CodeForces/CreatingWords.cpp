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
    string a, b; cin >> a >> b;
    char t = a[0];
    a[0] = b[0];
    b[0] = t;
    cout << a << ' ' << b << '\n';
}

void reset () {

}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        reset();
        solve();
    }

    return 0;
}
