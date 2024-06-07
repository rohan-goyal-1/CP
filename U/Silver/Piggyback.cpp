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

// Let's assume that the cows meet at point A:
//    -> That means the total energy taken is len_of_path(1 --> A) * B + len_of_path(2 --> A) * E + len_of_path(A --> N) * P
//    -> Compute the energy taken for each point of A --> find the miminum across all points

int b, e, p, n, m;

vector<vi> adj;

vi bfs (int node, int k) {
    vector<bool> visited(n, false);
    vi ans(n);
    queue<pi> q; q.push({node, 0});
    
    while (!q.empty()) {
        pi top = q.front(); q.pop();
        if (visited[top.first]) continue;
        visited[top.first] = true; ans[top.first] = top.second * k;
        for (int i : adj[top.first]) q.push({i, top.second + 1});
    }

    return ans;
}

int main () {
#ifndef LOCAL
    setIO("piggyback");
#else
    fastIO;
    clock_t tStart = clock();
#endif

    cin >> b >> e >> p >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x].pb(y); adj[y].pb(x);
    }

    vi bessie = bfs(0, b), elsie = bfs(1, e), end = bfs(n - 1, p);
    dbgm(bessie, elsie, end);

    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, bessie[i] + elsie[i] + end[i]);
    }
    cout << ans << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
