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

unordered_map<int, bool> targets;

int result (string dir) {
    int pos = 0, ans = 0;
    unordered_set<int> set;
    for (int i = 0; i < dir.size(); i++) {
        if (dir[i] == 'L') pos--;
        else if (dir[i] == 'R') pos++;
        else {
            if (targets[pos] && !set.count(pos)) { ans++; set.insert(pos); }
        }
    }
    return ans;
}

int main () {
    fastIO;
    
    int t, c; cin >> t >> c;
    for (int i = 0; i < t; i++) {
        int a; cin >> a;
        targets[a] = true;
    }
    string comm; cin >> comm;
    int pos = 0, ans = 0;
    ans = result(comm);
    dbg(ans);
    for (int i = 0; i < c; i++) {
        if (comm[i] == 'L') {
            comm[i] = 'R';
            ans = max(ans, result(comm));
            comm[i] = 'F';
            ans = max(ans, result(comm));
            comm[i] = 'L';
        }
        else if (comm[i] == 'R') {
            comm[i] = 'L';
            ans = max(ans, result(comm));
            comm[i] = 'F';
            ans = max(ans, result(comm));
            comm[i] = 'R';
        }
        else {
            comm[i] = 'L';
            ans = max(ans, result(comm));
            comm[i] = 'R';
            ans = max(ans, result(comm));
            comm[i] = 'F';
        }
    }
    cout << ans << nl;

    return 0;
}
