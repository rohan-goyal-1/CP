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

vector<vll> adj;
vll barns, subtrees;
ll n; ll avg;
vector<array<ll, 3>> ans;

void calc_subtrees (ll _n, ll p) {
    subtrees[_n] = barns[_n] - avg;
    for (auto child : adj[_n]) {
        if (child != p) {
            calc_subtrees(child, _n);
            subtrees[_n] += subtrees[child];
        }
    }
}

/**
* 4
2 1 4 5
1 2
2 3
2 4
**/
void fill_orders (ll _n, ll p) {
    for (ll child : adj[_n]) {
        if (child != p && subtrees[child] >= 0) { 
            fill_orders(child, _n);
            if (subtrees[child] != 0) 
                ans.pb({child + 1, _n + 1, subtrees[child]});
        }
    }

    for (ll child : adj[_n]) {
        if (child != p && subtrees[child] < 0) {
            ans.pb({_n + 1, child + 1, -subtrees[child]});
            fill_orders(child, _n);
        }
    }
}

int main () {
    fastIO;

    cin >> n;
    adj.resize(n), barns.resize(n), subtrees.resize(n);
    for (auto& b : barns) {
        cin >> b;
        avg += b;
    }
    avg /= n;

    for (ll i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    calc_subtrees(0, 0);
    dbgm(subtrees, avg, adj, barns);
    fill_orders(0, 0);

    cout << ans.size() << nl;
    for (auto& [a, b, c] : ans) cout << a << sp << b << sp << c << nl;

    return 0;
}
