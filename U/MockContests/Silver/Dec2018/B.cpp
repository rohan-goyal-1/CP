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

struct Cow {
    int s, a, t;
};
int n;
vector<Cow> cows;

int main () {
#ifndef LOCAL
    setIO("convention2");
#else
    fastIO;
#endif

    cin >> n; 
    for (int i = 0; i < n; i++) {
        int a, t; cin >> a >> t;
        cows.pb({i, a, t});
    }
    sort(all(cows), [](Cow a, Cow b) { return a.a == b.a ? a.s < b.s : a.a < b.a; });

    auto seniority_comp = [] (Cow a, Cow b) {
        return a.s < b.s;
    };
    priority_queue<Cow, vector<Cow>, decltype(seniority_comp)> pq(seniority_comp);
    int cur_time = -1, ans = 0;
    for (int i = 0; i < n || !pq.empty(); i++) {
        dbgm(cur_time, pq.size(), i, cows[i].a, ans);
        if (i < n && cows[i].a <= cur_time) {
            dbg("here");
            pq.push(cows[i]);
            ans = max(ans, cur_time - cows[i].a);
        }
        else if (pq.empty()) {
            cur_time = cows[i].a + cows[i].t;
        }
        else {
          Cow next = pq.top();
          ans = max(ans, cur_time - next.a);
          cur_time += next.t;
          pq.pop();
          i--;
        }
    }
    cout << ans << nl;

    return 0;
}
