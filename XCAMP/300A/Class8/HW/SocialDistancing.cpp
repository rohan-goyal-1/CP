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

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

ll n, m;
vpl grass;

bool works(ll d) {
    ll ret = 1, cur_cow = grass[0].f;
    for (auto& [a, b] : grass) {
        if (cur_cow + d <= a) {
            cur_cow = a;
            ret++;
        }
        while (cur_cow + d <= b && cur_cow + d >= a) {
            cur_cow += d;
            ret++;
        }
    }
    return ret >= n;
}

int main () {
    #ifndef LOCAL
    setIO("");
    #else
    fastIO;
    #endif

    cin >> n >> m;
    grass.resize(m);
    for (auto& [a, b] : grass) cin >> a >> b;
    srt(grass);

    ll lo = 0, high = grass[m - 1].s - grass[0].f + 1, ans;
    while (lo < high) {
        ll mid = (lo + high) / 2;
        if (works(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else high = mid;
    }
    cout << ans nl;
    

    return 0;
}
