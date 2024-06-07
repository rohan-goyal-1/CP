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

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

vector<vi> adj;
vi components;
int n, m, comp = 0;
string c;

void dfs (int node) {
    if (components[node] != 0) return;
    components[node] = comp;
    for (int a : adj[node]) {
        if (c[a] == c[node]) dfs(a);
    }
}

int main () {
#ifndef LOCAL
    setIO("milkvisits");
#else
    fastIO;
#endif

    cin >> n >> m >> c;
    adj.resize(n), components.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        if (components[i] == 0) {
            comp++;
            dfs(i);
        }
    }
    dbg(components);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        char pref; cin >> pref;
        if (c[a] == pref || c[b] == pref) cout << 1;
        else if (components[a] == components[b]) cout << 0;
        else cout << 1;
    }
    cout << nl;

    return 0;
}
