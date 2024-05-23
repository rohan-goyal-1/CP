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

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + "in.txt").c_str(), "r", stdin);
        freopen((input + "out.txt").c_str(), "w", stdout);
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

vector<vi> adj, comps;
vector<bool> vis, cycle;
int cur_comp = 0;

void dfs (int v, int p) {
    if (vis[v]) { 
        cycle[cur_comp] = true;
        return;  
    }
    vis[v] = true;
    comps[cur_comp].pb(v);
    for (int i : adj[v]) if (i != p) dfs(i, v);
}

int main () {
#ifndef LOCAL
    setIO("ruckus");
#else
    fastIO;
    clock_t tStart = clock();
#endif

    int n, l, k, m; cin >> n >> l >> k >> m;
    adj.resize(n); vis.resize(n, false); cycle.resize(n, false);
    for (int i = 0; i < l; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) { comps.pb(vi()); dfs(i, i); cur_comp++; } 
    }

    int ans = 0;
    for (int i = 0; i < cur_comp; i++) 
        ans += comps[i].size() >= m;
    dbg(ans);
    for (int i = 0; i < cur_comp && k; i++) {
        if (!cycle[i]) {
            int temp = comps[i].size(), cur = 0;
            int candies = -1;
            while (--temp) {
                cur++;
                if (cur == m) { candies++; cur = 0; }
            }
            k -= candies;
            ans += candies;
        }
    }
    for (int i = 0; i < cur_comp && k; i++) {
        if (cycle[i]) {
            int temp = comps[i].size(), cur = 0;
            int candies = -1;
            while (--temp) {
                cur++;
                if (cur == m) { candies++; cur = 0; }
            }
            k -= candies + 1;
            ans += candies - 1;
        }
    }
    cout << ans << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
