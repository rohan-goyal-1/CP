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
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define For(i, b) FOR(i, 0, b)
#define endl '\n'
#define sp << ' ' <<
#define nl << '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define srt(x) sort(all(x))
// #define max(n, m) ((n > m) ? n : m)
// #define min(n, m) ((n < m) ? n : m)

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

#define INF INT_MAX

array<int, 100> coins;
int n, x;
array<int, (size_t)1e6> dp;

int main () {
    fastIO;

    cin >> n >> x;
    For (i, n) {
        cin >> coins[i];
    }
    dp.fill(INF); dp[0] = 0;
    FOR (i, 1, x + 1) {
        For (j, n) {
            if (i - coins[j] >= 0) {
                int prev = dp[i - coins[j]];
                if (prev == INF) continue;
                dp[i] = min(dp[i], prev + 1);
            }
        }
    }
    dbg(dp, 0, x);
    cout << (dp[x] == INF ? -1 : dp[x]) nl;

    return 0;
}
