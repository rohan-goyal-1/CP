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
// #define max(n, m) ((n > m) ? n : m)
#define min(n, m) ((n < m) ? n : m)

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 
#define dbgm(...) 
#endif

inline void setIO(string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

bool reachable[201][201];
bool visited[201];
ll n; 

ll find_cows(ll cow) {
    visited[cow] = true;

    ll res = 1;
    For(i, n) {
        if (!visited[i] && reachable[cow][i]) {
            visited[i] = true;
            res += find_cows(i);
        }
    }
    dbgm(cow, res);
    return res;
}

int main() {
    #ifndef LOCAL
    setIO("moocast");
    #else
    fastIO;
    #endif

    cin >> n;
    vll x(n), y(n), pwr(n);
    For(i, n)
        cin >> x[i] >> y[i] >> pwr[i];

    For(i, n) {
        For(j, n) {
            ll dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
            reachable[i][j] = dist <= pow(pwr[i], 2);
            dbgm(i+1, j+1, reachable[i][j]);
        }
    }

    ll ans = 0;
    For(i, n) {
        fill(visited, visited + n, false);
        ans = std::max(ans, find_cows(i));
    }
    cout << ans nl;

    return 0;
}
