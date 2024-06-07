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

const ll MAXN = 1e5 + 5;
vpi adj[MAXN];

int main () {
#ifndef LOCAL
    setIO("revegetate");
#else
    fastIO;
#endif

    ll n, m; cin >> n >> m;
    For (i, m) {
        char t; ll a, b; cin >> t >> a >> b;
        a--, b--;
        adj[a].pb(mp(b, t));
        adj[b].pb(mp(a, t));
    }

    vll colors(n, -1);
    bool impossible = false;
    ll num = 0;
    For (i, n) {
        if (colors[i] != -1) continue;
        num++;
        queue<pair<ll, bool>> q; q.push(mp(i, true));
        while (!q.empty()) {
            pair<ll, bool> cur = q.front();
            q.pop();
            colors[cur.f] = cur.s;
            for (auto& [a, b] : adj[cur.f]) {
                bool type = b == 'S' ? cur.s : !cur.s;
                if (colors[a] == -1)
                    q.push(mp(a, type));
                else if (colors[a] != type) {
                    impossible = true;
                    break;
                }
            }
        }
    }
    dbgm(colors, num);
    if (impossible) 
        cout << 0 nl;
    else {
        cout << 1;
        For (i, num) 
            cout << 0;
        cout nl;
    }

    return 0;
}
