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
    string x; cin >> x;
    x = '0' + x;
    reverse(all(x));
    ll idx = 0;
    while (idx < x.length()) {
        ll d = x[idx] - '0';
        if (d >= 5) {
            while (d >= 5 && idx < x.length()) {
                x = string(idx + 1, '0') + x.substr(idx + 1);
                // For(j, idx + 1) x[j] = '0';
                idx++;
                d = x[idx] - '0';
            }
            x[idx] = ((x[idx] - '0') + 1) + '0';
        }
        else 
            idx++;
        dbgm(x, idx);
    }
    reverse(all(x));
    string ans = "";
    ll i = 0;
    for (; i < x.length() && x[i] == '0'; i++) {}
    FOR(j, i, x.length()) ans += x[j];
    cout << ans nl;
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
