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

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

const int MAXN = 1e5 + 5;

int n, m;
int cur_comp = 0;
vi adj[MAXN], comps[MAXN];
int comp_id[MAXN];

void dfs (int v) {
    if (comp_id[v] != -1) return;
    comp_id[v] = cur_comp; comps[cur_comp].pb(v);
    for (int c : adj[v]) dfs(c);
}

void solve () {
    cin >> n >> m;
    cur_comp = 0;
    for (int i = 0; i < n; i++) {
        comps[i].clear();
        comp_id[i] = -1;
        adj[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b); adj[b].pb(a);
    }
    
    for (int i = 0; i < n; i++) {
        if (comp_id[i] == -1) { dfs(i); cur_comp++; }
    }

    auto find_cost = [&] (int comp_a, int comp_b) -> ll {
        int ans = INT_MAX;
        for (int c : comps[comp_a]) {
            int temp = lower_bound(all(comps[comp_b]), c) - comps[comp_b].begin();
            dbg(temp);
            if (temp > 0) ans = min(ans, abs(comps[comp_b][temp - 1] - c));
            if (temp < comps[comp_b].size()) ans = min(ans, abs(comps[comp_b][temp] - c));
        }
        return (ll)ans * ans;
    };

    ll ans = find_cost(comp_id[0], comp_id[n - 1]);
    for (int i = 1; i < cur_comp; i++) {
        if (i == comp_id[n - 1]) continue;
        ans = min(ans, find_cost(comp_id[0], i) + find_cost(i, comp_id[n - 1]));
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

    int t;
    cin >> t;
    while (t--) {
        solve();
        // reset();
    }

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
