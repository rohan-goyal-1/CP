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

#define EM Type::EMPTY
#define WA Type::WALL
#define MO Type::MOVE

enum Type {
    EMPTY,
    WALL,
    MOVE
};

struct Cell {
    Type t;
    pi move_cell;
    char c;
    void operator=(string x) {
        if (x == "...") 
            t = EMPTY;
        else if (x == "###") 
            t = WALL;
        else {
            c = x[0];
            move_cell = {x[1] - '1', x[2] - '1'};
        }
    }
};

vector<bool> vis[25][25];

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int n; cin >> n;
    pi start;
    vector<vector<Cell>> grid(n, vector<Cell>(n));
    for (int i = 0; i < n; i++) {
        string c; cin >> c;
        for (int j = 0; j < n; j += 3) {
            string t = c.substr(j, j + 3);
            if (t == "BBB") { start = {i, j / 3}; t = "..."; }
            grid[i][j] = t;
        }
    }

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

