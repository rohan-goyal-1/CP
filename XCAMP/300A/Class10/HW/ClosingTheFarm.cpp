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
using namespace std;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define For(i, b) FOR(i, 0, b)
#define endl '\n'
#define sp << ' ' <<
#define nl << '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define srt(x) sort(all(x))
#define max(n, m) ((n > m) ? n : m)
#define min(n, m) ((n < m) ? n : m)
#define YES cout << "YES" nl
#define NO cout << "NO" nl

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 
#define dbgm(...) 
#endif

inline void setIO(string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

vll adj[3005];
bool visited[3005], closed[3005];
ll num_nodes = 0;

void dfs(ll barn) {
    if (visited[barn] || closed[barn]) return;

    visited[barn] = true;
    num_nodes++;
    for (auto& neigh : adj[barn]) 
        if (!visited[neigh]) dfs(neigh);
}

int main() {
    fastIO;

    ll n, m; cin >> n >> m;
    For (i, m) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vll close(n);
    for (auto& a : close) cin >> a;

    dfs(1);

    cout << (num_nodes == n ? "YES" : "NO") nl;

    For(i, n - 1) {
        num_nodes = 0;
        fill(all(visited), false);
        closed[close[i]] = true;

        dfs(close[n - 1]);

        cout << (num_nodes == n - i - 1 ? "YES" : "NO") nl;
    }

    return 0;
}
