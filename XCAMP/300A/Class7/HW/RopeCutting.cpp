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

ll n, k;
vll ropes;

int main () {
    fastIO;

    cin >> n >> k;
    ropes.resize(n);
    ll maxR = 0;
    for (auto& r : ropes) { 
        double a; cin >> a;
        r = ll(a * 100);
        maxR = max(maxR, r); 
    }
    
    ll l = 100, r = maxR; double ans = 0.0;
    while (l < r) {
        ll mid = (l + r) / 2;

        ll ret = 0;
        for (auto& a : ropes)
            ret += (a / mid);

        if (ret >= k) {
            ans = mid;
            l = mid;
        }
        else 
            r = mid;
    }
    ans /= 100.0;
    cout << fixed << setprecision(2) << ans nl;

    return 0;
}
