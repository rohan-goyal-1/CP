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
#include <stack>
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

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

ll n, m, maxW = -1, minW = LLONG_MAX;
vll cows;
vector<vpl> adj;

int main () {
    #ifndef LOCAL
    setIO("wormsort");
    #else
    fastIO;
    #endif

    cin >> n >> m;
    cows.resize(n);
    for (auto& a : cows) { cin >> a; a--; }
    adj.resize(n);
    For(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
        maxW = max(maxW, c);
        minW = min(minW, c);
    }

    ll l = minW, r = maxW + 1, ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;

        vll components(n, -1);
        dbgm(mid, ans);
        For(i, n) {
            if (components[i] != -1) continue;

            queue<ll> q; q.push(i);
            while (!q.empty()) {
                ll cur = q.front();
                q.pop();
                components[cur] = i;

                for (auto& [a, b] : adj[cur])
                    if (components[a] == -1 && b >= mid) q.push(a);
                dbg(components);
            }
            dbg(components);
        }
        bool works = true;
        For(i, n)
            if (components[i] != components[cows[i]]) { works = false; break; }

        if (works) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;

    }

    cout << (ans == maxW + 1 ? -1 : ans) nl;

    return 0;
}
