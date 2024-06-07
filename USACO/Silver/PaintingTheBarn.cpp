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

int grid[1001][1001];

int main () {
#ifndef LOCAL
    setIO("paintbarn");
#else
    fastIO;
#endif

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        grid[x1][y1]++;
        grid[x2][y2]++;
        grid[x2][y1]--;
        grid[x1][y2]--;
    }
    int ans = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (i > 0) grid[i][j] += grid[i-1][j];
            if (j > 0) grid[i][j] += grid[i][j-1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
            if (grid[i][j] == k) ans++;
        }
    }
    cout << ans << nl;


    return 0;
}
