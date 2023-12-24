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
vll nums;

bool works (ll mini) {
    ll tot = 0, count = 1;
    for (auto& a : nums) {
        if (tot + a <= mini) 
            tot += a;
        else {
            tot = a;
            count++;
        }
    }
    dbgm(count, tot, mini);
    return count <= m;
}

int main () {
    #ifndef LOCAL
    setIO("");
    #else
    fastIO;
    #endif

    cin >> n >> m;
    nums.resize(n);
    for (auto& a : nums) cin >> a;

    ll l = 0, r = 0;
    for (auto& a : nums) {
        l = max(l, a);
        r += a;
    }

    ll ans = 0;
    dbgm(l, r);
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (works(mid)) {
            dbgm("works", mid);
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans nl;

    return 0;
}
