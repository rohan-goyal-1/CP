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

struct Cow {
    int x, y, r;
};

int main () {
#ifndef LOCAL
    setIO("stampede");
#else
    fastIO;
#endif

    int n; 
    cin >> n; 
    vpi intervals;
    For (i, n) {
        int x, y, r; cin >> x >> y >> r;
        int first = (abs(x) - 1) * r;
        int second = abs(x) * r;
        intervals.pb(mp(first, second));
    }
    dbg(intervals);
    srt(intervals);
    vector<pi> ans;
    for (auto& i : intervals) {
        dbg(ans);
        if (ans.empty()) {
            ans.pb(i);
            continue;
        }
        auto back = ans.back();
        if (!(back.f <= i.f && back.s >= i.s)) 
            ans.pb(i);
    }
    cout << ans.size() nl;

    return 0;
}
