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
    // 4 5
    // 3 10 7 1
    // Find who wins normally --> ans is 0 for them:
    //  - For everyone else, need to eliminate eeryone before them
    //  - Eliminate all those above it in front
    int n, c; cin >> n >> c;
    vector<int> cands(n); for (int& i : cands) cin >> i;
    vector<int> ans(n);

    cands[0] += c;
    vector<int> mx(n);
    mx[n - 1] = cands[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        // cands[i] >= mx[i + 1]
        mx[i] = cands[i] >= mx[i + 1] ? cands[i] : mx[i + 1];
    }

    vector<ll> pfx(n + 1);
    for (int i = 0; i < n; i++) {
        pfx[i + 1] = pfx[i] + cands[i];
    }

    int idx = max_element(all(cands)) - cands.begin();
    for (int i = 0; i < n; i++) {
        if (i == idx)
            ans[i] = 0;
        else {
            ans[i] = i;
            if (mx[i] > cands[i] + pfx[i])
                ans[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
