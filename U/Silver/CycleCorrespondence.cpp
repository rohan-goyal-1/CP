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

int main () {
    fastIO;

    int n, k; cin >> n >> k;
    vi A(k), B(k); 
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;
    unordered_set<int> s1(all(A)), s2(all(B));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s1.count(i) == 0 && s2.count(i) == 0) ans++;
    }

    auto common = [&] () -> int {
        unordered_map<int, int> positions_a;
        for (int i = 0; i < k; i++) positions_a[A[i]] = i;
        vi offsets(k, 0);
        for (int i = 0; i < k; i++) {
            int val = B[i];
            if (positions_a.find(val) != positions_a.end()) {
                offsets[(i - positions_a[val] + k) % k]++;
            }
        } 
        return *max_element(all(offsets));
    };

    int a = common();
    reverse(all(A));
    int b = common();

    cout << ans + max(a, b) << nl;

    return 0;
}
