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

const int MAXN = 5e6 + 5;
bool prime[MAXN + 1];
vi last_max(4), turns(MAXN);

void precompute () {
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MAXN; p++) { 
        if (prime[p] == true) { 
            for (int i = p * p; i <= MAXN; i += p) 
                prime[i] = false; 
            last_max[p % 4] = p;
        } 
        turns[p] = (p - last_max[p]) / 2 + 1;
    } 
}

void solve () {
    int n; cin >> n;
    vi barns(n), wins(n);
    int ans = MAXN;
    for (auto b : barns) { cin >> b, ans = min(turns[b], ans); }
    for (int i = 0; i < n; i++) {
        wins[i] = barns[i] % 4;
    }

    for (int i = 0; i < n; i++) {
        if (turns[barns[i]] == ans) {
            if (wins[i]) 
                cout << "Farmer John" << nl;
            else 
                cout << "Farmer Nhoj" << nl;
            break;
        }
    }
}

int main () {
    fastIO;

    precompute();
    dbg(prime, 0, 10);
    int t; cin >> t;
    while (t--) solve();

    return 0;
}
