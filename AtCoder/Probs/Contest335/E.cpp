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

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int n, m; cin >> n >> m;
    vector<vi> adj(n); vi A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        adj[--a].pb(--b); adj[b].pb(a);
    }

    vi ans(n, 0); ans[0] = 1;
    priority_queue<int, vector<int>, greater<int>> q; q.push(0);
    while (!q.empty()) {
        int a = q.top(); q.pop();
        for (int v : adj[a]) {
            if (A[v] < A[a]) continue;
            int t = ans[a] + (A[v] != A[a] ? 1 : 0);
            if (t > ans[v]) {
                ans[v] = t;
                q.push(v);
            }
        }
    }
    cout << ans[n - 1] << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
