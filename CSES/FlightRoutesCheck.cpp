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

ll n, m;
vll can[100005][2];
bool visited[100005];

void dfs(ll start, ll turn) {
    visited[start] = true;
    for (auto& v : can[start][turn]) {
        if (!visited[v]) dfs(v, turn);
    }
}

int main() {
#ifndef LOCAL
    setIO("");
#else
    fastIO;
#endif

    cin >> n >> m;
    For(i, m) {
        ll a, b;
        cin >> a >> b;
        can[a][0].pb(b);
        can[b][1].pb(a);
    }
    dfs(1, 0);
    FOR(i, 1, n + 1) {
        if (!visited[i]) {
            cout << "NO" nl;
            cout << 1 sp i nl;
            return 0;
        }
    }

    memset(visited, false, sizeof(visited));
    dfs(1, 1);
    FOR(i, 1, n + 1) {
        if (!visited[i]) {
            cout << "NO" nl;
            cout << i sp 1 nl;
            return 0;
        }
    }
    cout << "YES" nl;

    return 0;
}
