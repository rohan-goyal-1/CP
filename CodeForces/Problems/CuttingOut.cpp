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

int n, k; 
vi counts(2e5 + 5);

bool works (int times) {
    int counter = 0;
    for (int c : counts) {
        counter += c / times;
    }
    if (counter >= k) return true;
    return false;
}

vi bs () {
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid  = (l + r) / 2;
        if (works(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else 
            r = mid - 1;
    }

    vi ret;
    for (int j = 0; j < counts.size(); j++) {
        for (int i = 1; i <= counts[j] / ans && ret.size() < k; i++) ret.pb(j);
    }
    return ret;
}

int main () {
    fastIO;

    cin >> n >> k;
    vi nums(n);
    for (int i : nums) cin >> i, counts[i]++;

    vi ans = bs();
    for (auto a : ans) cout << a << sp;
    cout << nl;

    return 0;
}
