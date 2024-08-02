#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
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
#define YES cout << "YES" nl
#define NO cout << "NO" nl

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

int k; vector<string> words;

bool works (int width) {
    int lines = 1, cur_length = 0;
    for (string word : words) {
        if (word.length() > width) return false;
        if (cur_length + word.length() <= width) {
            cur_length += word.length();
        }
        else {
            cur_length = word.length();
            lines++;
        }
    }
    return lines <= k;
}

int main () {
    fastIO;

    cin >> k;
    cin.ignore();
    string line;
    getline(cin, line);

    string cur = "";
    for (auto& c : line) {
        cur += c;
        if (c == ' ' || c == '-') { words.pb(cur); cur = ""; }
    }
    words.pb(cur);
    dbg(words);

    int l = 1, r = 1e6 + 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (works(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << nl;

    return 0;
}
