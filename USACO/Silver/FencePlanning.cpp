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

struct Cow {
    ll x, y;
    vll adj;
    bool visited = false;
};

vector<Cow> cows;
vll temp;

void dfs(ll cow) {
    cows[cow].visited = true;
    temp.pb(cow);
    for (auto& c : cows[cow].adj)
        if (!cows[c].visited)
            dfs(c);
}

int main() {
    #ifndef LOCAL
    setIO("fenceplan");
    #else
    fastIO;
    #endif

    ll n, m;
    cin >> n >> m;
    cows.resize(n);
    for (auto& c : cows) cin >> c.x >> c.y;

    For(i, m) {
        ll a, b; cin >> a >> b;
        --a, --b;
        cows[a].adj.pb(b);
        cows[b].adj.pb(a);
    }
    
    vector<vll> networks;
    For(i, n) {
        if (!cows[i].visited) {
            dfs(i);
            networks.pb(temp);
            temp.clear();
        }
    }
    
    ll ans = INT64_MAX;
    for (auto& net : networks) {
        ll minX = INT64_MAX, minY = INT64_MAX, maxX = -1, maxY = -1;
        for (auto& c : net) {
            minX = min(minX, cows[c].x);
			maxX = max(maxX, cows[c].x);
			minY = min(minY, cows[c].y);
			maxY = max(maxY, cows[c].y);
        }
        ll p = (maxX - minX) + (maxY - minY);
        ans = min(ans, p * 2);
    }
    cout << ans nl;

    return 0;
}
