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

vi papers;
int n, k, l;

bool works (int h) {
    int64_t need = 0;
    for (int i = 0; i < h; i++) {
        need += max(0ll, h - papers[i]);
    }
    return need <= (int64_t) k * l && papers[h - 1] + k >= h;
}

int main () {
    fastIO;

    cin >> n >> k >> l;
    papers.resize(n); for (int& p : papers) cin >> p;
    sort(all(papers), greater<int>());

    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (works(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << ans << nl;

    return 0;
}
