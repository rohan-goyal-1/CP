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
    vector<vi> grid(n, vi(n));

    // 123
    // 8-14
    // 765
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            grid[top][i] = num++;

        for (int i = top + 1; i <= bottom; i++)
            grid[i][right] = num++;

        for (int i = right - 1; i >= left; i--)
            grid[bottom][i] = num++;

        for (int i = bottom - 1; i > top; i--)
            grid[i][left] = num++;

        top++;
        bottom--;
        left++;
        right--;
    }
    grid[n / 2][n / 2] = 0;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (!grid[i][j]) cout << "T";
            else cout << grid[i][j];
            cout << " \n"[j == n - 1];
        }
    }

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
