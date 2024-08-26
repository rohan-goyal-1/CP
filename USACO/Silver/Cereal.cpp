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

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

int main () {
#ifndef LOCAL
    setIO("cereal");
#else
    fastIO;
    clock_t tStart = clock();
#endif

    int n, m; cin >> n >> m;
    vector<pi> pref(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; --a, --b;
        pref[i] = {a, b};
    }
    vector<int> by_who(m, -1);
    vi ans;
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        int cur = i, next = pref[i].first;
        while (true) {
            if (by_who[next] == -1) {
                count++;
                by_who[next] = cur;
                break;
            }
            else if (by_who[next] < cur) {
                break;
            }
            else {
                int by = by_who[next];
                by_who[next] = cur;
                if (next == pref[by].second) break;
                cur = by;
                next = pref[by].second;
            }
        }
        ans.pb(count);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[n - 1 - i] << nl;
    }
#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
