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
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

void solve () {
    int n; cin >> n;
    vi glasses(n); for (int& g : glasses) cin >> g;
    vi pfx_even({0}), pfx_odd({0});
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1)
            pfx_even.pb(pfx_even.back() + glasses[i]);
        else
            pfx_odd.pb(pfx_odd.back() + glasses[i]);
    }
    int l = 1, r = 1;
    while (l <= r && l < pfx_even.size() && l < pfx_odd.size() && r < pfx_odd.size() && r < pfx_even.size()) {
        int even = pfx_even[r] - pfx_even[l - 1], odd = pfx_odd[r] - pfx_odd[l - 1];
        if (even == odd) { YES; return; }
        else if (even > odd) r++;
        else l++;
    }
    NO;
}

int main () {
    fastIO;

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
