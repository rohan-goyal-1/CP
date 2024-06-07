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

ll n;
vpl cows;

ll dist (pll a, pll b) {
    return pow(a.f - b.f, 2) + pow(a.s - b.s, 2);
}

bool works (ll X) {
    queue<ll> q; q.push(0);
    bool visited[n]; visited[0] = true;
    while (!q.empty()) {
        For(i, n) {
            if (!visited[i] && dist(cows[i], cows[q.front()]) <= X) {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }

    for (auto& a : visited) 
        if (!a) return false;
    return true;
}

int main () {
    #ifndef LOCAL
    setIO("moocast");
    #else
    fastIO;
    #endif

    cin >> n; cows.resize(n);
    for (auto& [x, y] : cows) cin >> x >> y;

    ll l = 0, r = LLONG_MAX, ans;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (works(mid)) {
            ans = mid;
            r = --mid;
        }
        else l = ++mid;
    }
    cout << ans nl;

    return 0;
}
