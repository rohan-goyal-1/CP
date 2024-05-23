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

void solve () {
    int n, k; cin >> n >> k;
    k = min(k, n - k);
    vi w(n); for (auto& W : w) cin >> W;
    sort(all(w));
    int idx = 0, sum1 = 0, sum2 = 0;
    for (idx = 0; idx < k && idx < n; idx++)
        sum1 += w[idx];
    for (; idx < n; idx++ )
        sum2 += w[idx];

    cout << sum2 - sum1 << nl;
}

int main () {
    fastIO;

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
