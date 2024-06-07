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

    string s; cin >> s;
    int n = (int)s.size();
    vi pfxC(n + 1, 0), pfxO(n + 1, 0), pfxW(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pfxC[i + 1] += pfxC[i] + (s[i] == 'C' ? 1 : 0);
        pfxO[i + 1] += pfxO[i] + (s[i] == 'O' ? 1 : 0);
        pfxW[i + 1] += pfxW[i] + (s[i] == 'W' ? 1 : 0);
    }
    dbgm(pfxC, pfxO, pfxW);

    string ans = "";
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; 
        int C = pfxC[r] - pfxC[l - 1]; 
        int O = pfxO[r] - pfxO[l - 1]; 
        int W = pfxW[r] - pfxW[l - 1];

        ans += ((O + W) % 2 == 0 && (C + O) % 2 == 1 ? "Y" : "N");
    }
    cout << ans << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

