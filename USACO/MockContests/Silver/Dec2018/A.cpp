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

int n, m, c, ans;
vi cows;

bool works (int time) {
    int buses = 1, count = 0, start = 0;
    while (count < n) {
        if (cows[count] - cows[start] > time || count - start + 1 > c) {
            buses++;
            start = count;
        }
        count++;
    }
    return buses <= m;
}

int main () {
#ifndef LOCAL
    setIO("convention");
#else
    fastIO;
#endif

    cin >> n >> m >> c; cows.resize(n);
    for (int& a : cows) cin >> a;
    sort(all(cows));

    int l = 0, r = cows[n - 1] - cows[0];
    while (l <= r) {
        int mid = (l + r) / 2;
        if (works(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << nl;

    return 0;
}
