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
    setIO("pairup");
#else
    fastIO;
#endif

    int n=0; cin >> n;
    vpi cows(n);
    for (auto& c : cows) cin >> c.second >> c.first;
    sort(all(cows));
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        dbg(ans);
        if (cows[l].second == 0) l++;
        if (cows[r].second == 0) r--;

        int take = min(cows[l].second, cows[r].second);
        if (l == r) take /= 2;
        ans = max(ans, cows[l].first + cows[r].first);
        cows[l].second -= take, cows[r].second -= take;
    }
    cout << ans << nl;

    return 0;
}
