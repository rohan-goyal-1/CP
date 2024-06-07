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

const int dX[4]{1, 0, -1, 0}, dY[4]{0, 1, 0, -1};

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

int main () {
#ifndef LOCAL
    setIO("herding");
#else
    fastIO;
#endif

    int n; cin >> n;
    vi cows(n); for (int& c : cows) cin >> c;
    sort(all(cows));

    // 4 _ _ 7 _ 9 _ _ _ 13

    // calc min
    int min_ans = 0;
    if (cows[n - 2] - cows[0] == n - 2 && cows[n - 1] - cows[n - 2] > 2) min_ans = 2;
    else if (cows[n - 1] - cows[1] == n - 2 && cows[1] - cows[0] > 2) min_ans = 2;
    else {
        int best = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n - 1 && cows[j+1] - cows[i] <= n - 1) j++;
            best = max(best, j - i + 1);
        }
        min_ans = n - best;
    }
    cout << min_ans << nl;

    // calc max
    int max_ans = 0;
    if (cows[1] - cows[0] > cows[n - 1] - cows[n - 2]) {
        for (int i = 0; i < n - 2; i++) 
            max_ans += cows[i + 1] - cows[i] - 1;
    }
    else {
        for (int i = n - 1; i > 1; i--)
            max_ans += cows[i] - cows[i - 1] - 1;
    }
    cout << max_ans << nl;

    return 0;
}
