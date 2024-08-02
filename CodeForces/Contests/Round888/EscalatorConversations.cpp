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
#define endl '\n'
#define sp << ' ' <<
#define nl << '\n'
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
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

inline void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

void solve() {
  ll n, m, k, h;
  cin >> n >> m >> k >> h;
  vll heights(n);
  FOR(i, 0, n) cin >> heights[i];

  ll ans = 0;
  FOR(i, 0, n) {
    // 7 1 4 66
    // 18 66 39 83 48 99 79
    ll dif = abs(heights[i] - h);
    ll num_steps = dif / k;
    if (num_steps == 0) continue;
    if (num_steps * k == dif && num_steps < m && dif % k == 0)
      ans++;
  }
  cout << ans nl;
}

int main() {
  setIO("");

  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
