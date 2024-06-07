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

struct Event {
    int x, y, t;
};

bool cmp (Event a, Event b) {
    return a.t < b.t;
}


bool works (Event a, Event b) {
    ull dist = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return dist <= (a.t - b.t) * (a.t - b.t);
}

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int g, n; cin >> g >> n;
    vector<Event> gs(g), cs(n);
    for (Event& a : gs) cin >> a.x >> a.y >> a.t;
    for (Event& a : cs) cin >> a.x >> a.y >> a.t;

    sort(all(gs), [=] (Event a, Event b) -> bool { return a.t < b.t; });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(gs), cs[i], cmp);

        if (it == gs.begin()) {
            if (works(*it, cs[i])) ans++;
        }
        else if (it == gs.end()) {
            if (works(cs[i], *(--it))) ans++;
        }
        else {
            if (works(*it, cs[i]) && works(cs[i], *(--it))) ans++;
        }
    }
    
    cout << n - ans << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

