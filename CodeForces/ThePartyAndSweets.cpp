#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
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
#define endl '\n'
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
#define max(n, m) ((n > m) ? n : m)
#define min(n, m) ((n < m) ? n : m)
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

void solve () {
    int n, m; cin >> n >> m;
    vi B(n); for (int& b : B) cin >> b;
    vi G(m); for (int& g : G) cin >> g;

    sort(all(B)); sort(all(G));

    // Impossible case 
    if (B[n - 1] > G[0]) { cout << -1 << nl; return; }

    ll ans = 0;
    for (ll b : B) { ans += (b * m); }
    // Greedily assign to the last boy to minimize amount
    for (int i = 1; i < m; i++) ans += G[i] - B[n - 1];
    // If not possible to have been given by the last boy, take from the second to last boy
    if (G[0] != B[n - 1]) ans += G[0] - B[n - 2];
    
    cout << ans << nl;
}

int main () {
    fastIO;

    int t = 1;
    while (t--)
        solve();

    return 0;
}
