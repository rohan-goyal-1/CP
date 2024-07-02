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
    vector<int> one(n), two(n);
    for (int& i : one) cin >> i;
    for (int& i : two) cin >> i;

    int a = 0, b = 0;
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        if (one[i] >= 0 && two[i] <= 0) {
            a += one[i];
            used[i] = true;
        }
        else if (one[i] <= 0 && two[i] >= 0) {
            b += two[i];
            used[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (one[i] >= 0 && two[i] >= 0) {
            int* c = a < b ? &a : &b;
            *c += one[i];
        }
        else {
            int* c = a > b ? &a : &b;
            *c += one[i];
        }
    }

    cout << min(a, b) << '\n';
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
