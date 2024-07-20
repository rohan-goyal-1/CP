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

typedef struct {
    ll a, b, c;
} Friend;

#define MAXN 100

int n, t_c, t_m;
Friend fs[MAXN];
int need[MAXN];

bool works (ll moony) {
    ll mx = 0, my = 0;
    for (int i = 0; i < n; i++) {
        auto [a, b, c] = fs[i];
        if (a > b) {
            mx = max(mx, (need[i] - moony * b + a - b - 1) / (a - b));
        }
        else if (b > a) {
            my = max(my, (need[i] - moony * a + b - a - 1) / (b - a));
        }
        else {
            if (b * moony < need[i]) {
                return false;
            }
        }
    }

    if (mx >= t_c || my >= t_m || mx + my > moony) {
        return false;
    }

    return true;
}

void solve () {
    cin >> n >> t_c >> t_m;
    for (int i = 0; i < n; i++) {
        cin >> fs[i].a >> fs[i].b >> fs[i].c;
    }

    for (int i = 0; i < n; i++) {
        need[i] = max(0ll, fs[i].a * t_c + fs[i].b * t_m - fs[i].c);
    }

    ll ans = 0;
    ll lo = 0, hi = 2e18;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (works(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
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
