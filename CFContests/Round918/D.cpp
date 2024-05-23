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

bool is_cons (char c) {
    return c == 'b' || c == 'c' || c == 'd';
}

void solve () {
    int n; string s;
    cin >> n >> s;
    if (n <= 3) {
        cout << s << nl;
        return;
    }
    vi cons;
    for (int i = 0; i < n; i++) {
        if (is_cons(s[i]) && i != n - 1 && !is_cons(s[i + 1])) cons.pb(i);
    }
    set<int> dots;
    for (int c : cons) {
        if (c >= n - 3) dots.insert(c); 
        else if (is_cons(s[c + 3]) && is_cons(s[c + 2])) dots.insert(c + 3);
        else dots.insert(c + 2);
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (dots.count(i) > 0) ans += '.';
        ans += s[i];
    }
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
