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
#define YES cout << "YES" nl
#define NO cout << "NO" nl

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

void solve() {
    ll n; cin >> n;
    vll a(n * (n - 1) / 2); for (auto& e : a) cin >> e;

    vll ans(n, 0);
    ll idx = 0;

    For(i, n) {
        FOR(j, i + 1, n) {
            ans[i] = ans[j] = a[idx];
            idx++;
        }
    }

    for (auto& e : ans) cout << e << ' ';
    cout nl;
}

int main() {
    #ifndef LOCAL
    setIO("");
    #else
    fastIO;
    #endif

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
