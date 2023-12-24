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

int main () {
    fastIO;

    string str; cin >> str;
    vi alph(26, 0);
    for (char& c : str)
        alph[c - 'A']++;

    dbg(alph);
    int odd = 0;
    for (int i : alph) {
        if (i % 2 == 1) odd++;
    }
    if (odd > 1) cout << "NO SOLUTION" << nl;
    else {
        string palin;
        char odd_c;
        for (int i = 0; i < 26; i++) {
            if (alph[i] % 2 == 1) odd_c = char(65 + i);
            for (int j = 0; j < alph[i] / 2; j++) palin += char(65 + i);  
        }
        dbg(palin);
        dbgm(odd, odd_c);
        string ans = palin;
        reverse(all(palin));
        if (odd != 0) ans += odd_c;
        ans += palin;
        cout << ans << nl;
    }

    return 0;
}
