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
bool visited[100005];

void dfs(ll n) {
    if (visited[n]) return;
    visited[n] = true;
    for (auto& a : adj[n]) dfs(a);
}

int main() {
    #ifndef LOCAL
    setIO("");
    #else
    fastIO;
    #endif

    ll n, m;
    cin >> n >> m;
    For(i, m) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    vpl ans;
    FOR(i, 1, n + 1) {
        if (!visited[i]) {
            adj[1].pb(i);
            adj[i].pb(1);
            ans.pb(mp(i, 1));
            dfs(i);
        }
    }
    cout << ans.size() nl;
    for (auto& a : ans)
        cout << a.f sp a.s nl;

    return 0;
}
