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

int n, k, max_tree = -1, b, ans = -1;
vi trees;

bool cmp (int i, int j) {
    return i % b > j % b;
}

int main () {
#ifndef LOCAL
    setIO("berries");
#else
    fastIO;
#endif

    cin >> n >> k; trees.resize(n);
    for (auto& i : trees) cin >> i, max_tree = max(max_tree, i);

    for (b = 1; b < max_tree; b++) {
        int baskets = 0;
        for (int& i : trees) baskets += i / b;
        if (baskets >= k) ans = max(ans, k / 2 * b); 
        else {
            sort(all(trees), cmp);
            int idx = k / 2 - baskets, temp = 0;
            int left = k / 2;
            if (idx < 0) {
                left += idx;
                temp += abs(idx) * b;
                idx = 0;
            }
            for (int i = idx; i - idx < left && i < n; i++)
                temp += trees[i] % b;
            ans = max(temp, ans);
        }
    }
    cout << ans << nl;

    return 0;
}
