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

int main () {
    fastIO;

    // Input
    int n, q; cin >> n >> q;
    string fence; cin >> fence;

    // Precompute pfx
    vi pfx(n + 1);
    stack<int> s;
    For (i, n) {
        pfx[i + 1] = pfx[i];
        while (!s.empty() && s.top() > fence[i]) s.pop();
        if (s.empty() || fence[i] > s.top()) { s.push(fence[i]); pfx[i + 1]++; }
    }
    dbg(pfx);

    // Precompute sfx
    vi sfx(n + 1);
    stack<int> st;
    for (int i = n; i > 0; i--) {
        sfx[i - 1] = sfx[i];
        while (!st.empty() && st.top() > fence[i]) st.pop();
        if (st.empty() || fence[i] > st.top()) { st.push(fence[i]); sfx[i - 1]++; }
    }
    dbg(sfx);

    // Compute based on range
    For (i, q) {
        int a, b;
        cin >> a >> b;
        cout << pfx[a - 1] + sfx[b - 1] - 1 nl;
    }

    return 0;
}
