#include <algorithm>
#include <array>
#include <cassert>
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
#pragma GCC optimize("O3,unroll-loops")

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

const int dX[4]{1, 0, -1, 0}, dY[4]{0, 1, 0, -1};

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int n; cin >> n;
    vector<vi> grid(n + 1, vi(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            grid[i][j] = (c == 'R' ? 1 : 0);
        }
        cin >> grid[i][n];
    }
    for (int i = 0; i < n; i++) {
        cin >> grid[n][i];
    }

    vector<vi> dp(n + 1, vi(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                dp[i][j + 1] += dp[i][j];
            }
            else {
                dp[i + 1][j] += dp[i][j];
            }
        }
    }

    int cost = 0;
    for (int i = 0; i < n; i++) cost += dp[n][i] * grid[n][i] + dp[i][n] * grid[i][n];
    cout << cost << nl;

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; x--, y--;
        grid[x][y] = !grid[x][y];
        int a = x, b = y;
        while (a != n && b != n) {
            if (grid[a][b]) b++;
            else a++;
            dp[a][b] += dp[x][y];
        }
        cost += dp[x][y] * grid[a][b];

        a = x, b = y;
        if (grid[x][y]) a++;
        else b++;
        dp[a][b] -= dp[x][y];
        while (a != n && b != n) {
            if (grid[a][b]) b++;
            else a++;
            dp[a][b] -= dp[x][y];
        }
        cost -= dp[x][y] * grid[a][b];

        cout << cost << nl;
    }

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

