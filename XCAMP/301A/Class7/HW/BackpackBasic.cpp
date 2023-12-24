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

const int MAXN = 30;
int weights[MAXN], values[MAXN];

int kp (int maxI, int capacity) {
    if (capacity == 0 || maxI < 0) return 0;
    if (capacity >= weights[maxI]) {
        int max_value_without_item = kp(maxI - 1, capacity);
        int max_value_with_item = values[maxI] + kp(maxI - 1, capacity - weights[maxI]);
        return max(max_value_without_item, max_value_with_item);
    }
    return kp(maxI - 1, capacity);
}

int main () {
    fastIO;

    int n, w; cin >> n >> w;
    For (i, n) {
        cin >> weights[i] >> values[i];
    }

    cout << kp(n - 1, w) nl;

    return 0;
}
