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
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

vector<vll> adj;
vll comps;
string c;
ll n, m, cur = 0;

void dfs (ll idx) {
    if (comps[idx] != 0) return;
    comps[idx] = cur;
    for (auto& a : adj[idx]) {
        if (c[a] == c[idx]) dfs(a);
    }
}

int main () {
#ifndef LOCAL
    setIO("milkvisits");
#else
    fastIO;
#endif

    cin >> n >> m >> c;
    adj.resize(n), comps.resize(n);
    For (i, n - 1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }

    For (i, n) {
        if (comps[i] == 0) {
            cur++;
            dfs(i);
        }
    }

    dbgm(comps, adj);

    For (i, m) {
        int a, b; cin >> a >> b;
        char cow; cin >> cow;
        if (c[a] == cow) cout << 1;
        else if (comps[a] == comps[b] && a != b) cout << 1;
        else cout << 0;
    }
    cout nl;

    return 0;
}
