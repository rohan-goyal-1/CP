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

int n, m; 
vector<string> spotty, plain;

bool works (int x, int y, int z) {

}

int main () {
#ifndef LOCAL
    setIO("cownomics");
#else
    fastIO;
#endif

    cin >> n >> m;
    spotty.resize(n), plain.resize(n);
    for (auto& s : spotty) cin >> s;
    for (auto& p : plain) cin >> p;

    set<array<int, 3>> s;
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            for (int x = j + 1; x < m; x++) {
                if (s.find({i, j, x}) == s.end() && works(i, j, x)) {
                    ans++;
                    s.insert({i, j, x});
                }
            }

    cout << ans << nl;

    return 0;
}
