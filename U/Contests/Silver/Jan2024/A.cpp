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
    int n, q, c; cin >> n >> q >> c;
    vi cows(n); for (int& cow : cows) cin >> cow;
    vpi pairs(q); for (auto& [a, b] : pairs) cin >> b >> a, --b, --a;
    sort(all(pairs), [&] (pi a, pi b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });
    vi H(q), A(q); 
    for (int i = 0; i < q; i++) {
        H[i] = pairs[i].first;
        A[i] = pairs[i].second;
    }

    vector<bool> zeros(n);
    dbgm(H, A);
    for (int i = 0; i < n; i++) {
        if (cows[i] == 0) { zeros[i] = true; cows[i] = 1; }
    }

    vi maxArr(n, -1); maxArr[0] = cows[0];
    for (int i = 1; i < n; i++) {
        maxArr[i] = max(maxArr[i - 1], cows[i]);
    }
    dbg(maxArr);

    for (int i = 0; i < q; i++) {
        if (zeros[H[i]]) {
            cows[H[i]] = maxArr[A[i]] + 1;
            maxArr[H[i]] = max(maxArr[H[i]], cows[H[i]]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (cows[i] > c) {
            cout << -1 << nl;
            return;
        }
    }
    for (int i = 0; i < n; i++) 
        cout << cows[i] << " \n"[i == n - 1];
}

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int t; cin >> t;
    while (t--) solve();

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

