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
#define YES cout << "YES" nl
#define NO cout << "NO" nl

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

ll prime (ll n) { 
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return i;
    }
    return n;
}

void solve () {
    ll a, b; cin >> a >> b;
    ll smallA = prime(a);
    ll smallB = prime(b);
    ull ans = b;
    if (a == 1) ans *= smallB;
    else ans *= min(smallA, smallB);
    cout << ans << nl;
}

int main () {
    fastIO;

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
