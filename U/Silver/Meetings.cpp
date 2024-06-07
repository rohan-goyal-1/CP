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
    int w, x, d;
};
int n, l, sum = 0;
ll T = 0, ans = 0;
vector<Cow> cows;

void calc_t () {
    vpi times;
    for (int i = 0; i < n; i++) {
        Cow c = cows[i];
        if (c.d == -1) 
            times.pb({c.x, i});
        else 
            times.pb({l - c.x, i});
    }
    sort(all(times));
    dbg(times);
    
    ll temp = 0;
    int idx = 0;
    while (temp <= ceil(sum / 2) && idx < n) {
        dbgm(temp, ceil(sum / 2));
        temp += cows[times[idx].second].w;
        T = max(T, times[idx].first);
        idx++;
    }
}

void calc_collisions () {
    queue<int> q;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i].d == -1) {
            while (!q.empty() && q.front() + 2 * T < cows[i].x) q.pop();
            ans += q.size();
        }
        else q.push(cows[i].x);
    }
}

int main () {
#ifndef LOCAL
    setIO("meetings");
#else
    fastIO;
#endif

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int w, x, d; cin >> w >> x >> d;
        cows.pb({w, x, d});
        sum += cows.back().w;
    }
    calc_t();
    dbg(T);
    sort(all(cows), [](Cow a, Cow b) { return a.x < b.x; });
    calc_collisions();
    cout << ans << nl;


    return 0;
}
