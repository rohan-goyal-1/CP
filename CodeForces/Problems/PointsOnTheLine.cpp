#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;
#define sp ' '
#define nl '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl
#pragma GCC optimize("O3,unroll-loops")

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

const int dX[4]{1, 0, -1, 0}, dY[4]{0, 1, 0, -1};

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

void solve () {
    int n, d; cin >> n >> d;
    vi x(n); for (int& i : x) cin >> i;
    sort(all(x));
    int l = 0, r = n - 1;
    int ans = 0;
    while (x[r] - x[l] > d) {
        dbgm(x, l, r);
        ans++;
        if (x[r] - x[r - 1] > x[l + 1] - x[l]) {
            r--;
        }
        else {
            l++;
        }
    }
    cout << ans << nl;
}

void reset () {

}

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int t = 1;
    while (t--) {
        reset();
        solve();
    }

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
