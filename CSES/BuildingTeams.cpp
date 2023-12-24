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

vll adj[100005];
vll colors(100005);
bool impossible = false;

void color(ll node, ll c) {
    if (colors[node] != 0) return;

    colors[node] = c;
    ll ncolor = c == 1 ? 2 : 1;
    for (auto& frend : adj[node]) {
        if (colors[frend] == c) {
            impossible = true;
            return;
        }
        if (colors[frend] == 0) color(frend, ncolor);
    }
}

int main() {
    #ifndef LOCAL
    setIO("");
    #else
    fastIO;
    #endif

    ll n, m; cin >> n >> m;
    For(i, m) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    For(i, n) {
        if (colors[i] == 0)
            color(i, 1);
    }
    
    if (impossible) cout << "IMPOSSIBLE" nl;
    else {
        FOR(i, 1, n + 1) cout << colors[i] << ' ';    
        cout nl;
    }

    return 0;
}
