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

// 5 6
// [1,5,11,9,1]
//
// 0, 3, 9, 7, 0

int n, p;
vi towers;
bool works (int throws) {
    vi temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = max(0, towers[i] - throws);
    }
    int sum = 0;
    for (auto a : temp) {
        sum += a / p + (a % p > 0);
    }
    return sum <= throws;
}

int main () {
    fastIO;

    cin >> n >> p;
    towers.resize(n);
    for (int& i : towers) cin >> i;

    int l = 1, r = 1e9 + 10, ans;
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
