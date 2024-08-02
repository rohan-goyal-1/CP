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

int n;
// set to ensure unique values of adjacency 
vector<set<int>> adj;
vector<bool> visited;

void solve () {
    cin >> n;
    adj.clear(); adj.resize(n); visited.clear(); visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        adj[i].insert(a);
        adj[a].insert(i);
    }

    // find the components (linear or cyclic)
    // use this information to find min and max
    int lines = 0, cycles = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        queue<int> q; q.push(i);
        vi component;
        while (!q.empty()) {
            int top = q.front(); q.pop();
            if (visited[top]) continue;
            visited[top] = true; component.pb(top);
            for (int c : adj[top]) q.push(c);
        }
        for (int c : component) {
            if (adj[c].size() == 1) { lines++; cycles--; break; }
        }
        cycles++;
    }
    uint thing = 0;

    cout << cycles + min(1, lines) << sp << cycles + lines << nl;
}

int main () {
    fastIO;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
