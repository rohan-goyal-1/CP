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

struct Event {
    ll x, y, t;
    Event (ll x, ll y, ll t) : x(x), y(y), t(t) {}
    bool operator<(const Event& a) const { return t < a.t; }
};

int main() {
    #ifndef LOCAL
    setIO("");
    #else
    fastIO;
    #endif

    ll g, n; cin >> g >> n;
    set<Event> grazings;
    For (i, g) {
        ll x, y, t; cin >> x >> y >> t;
        grazings.insert(Event(x, y, t));
    }

    ll ans = 0;
    For(i, n) {
        ll x, y, t; cin >> x >> y >> t;
        auto next = grazings.lower_bound(Event(x, y, t));
        bool innocent = false;
        if (next != grazings.end()) {
            ll dx = next->x - x, dy = next->y - y, dt = next->t - t;
            innocent = (dx * dx) + (dy * dy) > (dt * dt);
        }

        if (next != grazings.begin()) {
            --next;
            ll dx = next->x - x, dy = next->y - y, dt = next->t - t;
            innocent = innocent || (dx * dx) + (dy * dy) > (dt * dt);
        }

        ans += (innocent ? 1 : 0);
    }
    cout << ans nl;

    return 0;
}
