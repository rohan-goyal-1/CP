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

vector<vi> ranks;

int find (int num, int row) {
    for (int i = 0; i < ranks[row].size(); i++) {
        if (ranks[row][i] == num) return i;
    }
    return -1;
}

int main () {
#ifndef LOCAL
    setIO("gymnastics");
#else
    fastIO;
#endif

    int k, n; cin >> k >> n;
    ranks.resize(k, vi(n));
    for (auto& ra : ranks) {
        for (auto& r : ra) cin >> r, --r;
    }
    dbg(ranks);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool consistent = true;
            for (int x = 0; x < k; x++) {
                if (find(i, x) > find(j, x)) consistent = false;
            }
            ans += consistent;
        }
    }
    cout << ans - n << nl;

    return 0;
}
