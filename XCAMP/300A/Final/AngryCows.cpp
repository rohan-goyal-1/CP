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

ll n, k;
vll bales;

bool works(ll r) {
    ll index = 0;
    for (ll cows = 0; cows < k && index < n; cows++) {
        ll range = bales[index] + r * 2;
        while (index < n- 1 && bales[index + 1] <= range) index++;
        index++;
    }

    return index >= n;
}

int main () {
    fastIO;

    cin >> n >> k;
    bales.resize(n);
    for (auto& a : bales) cin >> a;
    srt(bales);

    ll lo = 1, high = bales[n - 1] - bales[0], ans = 1e9;
    while (lo <= high) {
        ll mid = (lo + high) / 2;
        if (works(mid)) {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else 
            lo = mid + 1;
    }
    cout << ans nl;

    return 0;
}
