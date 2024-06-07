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

int scuffed_log (int x) {
    int days = 0, cur = 1;
    while (cur < x) {
        cur *= 2;
        days++;
    }
    return days;
}

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int n; cin >> n;
    vector<vi> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    vector<bool> vis(n, false);
    int ans = 0;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int top = q.front(); q.pop();
        vis[top] = true;
        int cur = 0;
        for (int c : adj[top]) {
            if (!vis[c]) {
                cur++;
                q.push(c);
            }
        }
        ans += scuffed_log(cur + 1) + cur;
    }
    cout << ans << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

