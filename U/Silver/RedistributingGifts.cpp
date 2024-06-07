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

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

int n; 
vector<vi> adj;
bool visited[501][501];

void dfs (int node, int orig) {
    if (visited[node][orig]) return;
    visited[node][orig] = true;
    for (auto& c : adj[node]) dfs(c, orig);
}

int main () {
    fastIO;

    cin >> n; adj.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a; --a;
            adj[i].pb(a);
        }
        while (adj[i].back() != i) adj[i].pop_back();
    }
    dbg(adj);

    for (int i = 0; i < n; i++)
        dfs(i, i);

    for (int i = 0; i < n; i++) {
        for (auto& c : adj[i]) {
            if (visited[i][c]) {
                cout << c + 1 << nl;
                break;
            }
        }
    }

    return 0;
}
