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

    string s, t; cin >> s >> t;
    int freqT[18], freqS[18];
    for (char c : s)
        freqS[c - 'a']++;
    for (char c : t)
        freqT[c - 'a']++;



    auto solve = [&]() -> string {
        string r; cin >> r;
        int sum1 = 0, sum2 = 0;
        for (char c : r) sum1 += freqS[c - 'a'], sum2 += freqT[c - 'a'];
        if (sum1 != sum2) return "N";

        for (int i = 0; i < r.size(); i++) {
            for (int j = i + 1; j < r.size(); j++) {
                if (!works[r[i] - 'a'][r[j] - 'a']) return "N";
            }
        }

        return "Y";
    };
    string ans = "";
    int q; cin >> q;
    while (q--) {
        ans += solve();
    }
    cout << ans << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

