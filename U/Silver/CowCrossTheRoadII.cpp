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
#include <stack>
#include <numeric>
using namespace std;
#define endl '\n'
#define sp ' '
#define nl '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
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

int main () {
#ifndef LOCAL
    setIO("maxcross");
#else
    fastIO;
#endif

    int n, k, b; cin >> n >> k >> b;
    vi lights(n); 
    for (int i = 0; i < b; i++) {
        int j; cin >> j;
        lights[--j] = 1;
    }

    vi pfx(n + 1);
    for (int i = 1; i <= n; i++)
        pfx[i] = pfx[i - 1] + lights[i - 1];

    int ans = INT_MAX;
    for (int i = n; i > k; i--)
        ans = min(ans, pfx[i] - pfx[i - k]);
    cout << ans << nl;

    return 0;
}
