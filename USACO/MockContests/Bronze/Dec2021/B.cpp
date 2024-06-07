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

int sign(ll x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}

int main() {
  setIO("");

  ll n;
  cin >> n;
  ll d[n], p[n], t[n];
  FOR(i, 0, n) cin >> p[i];
  FOR(i, 0, n) {
    cin >> t[i];
    d[i] = p[i] - t[i];
  }

  ll non_zero = 0, ans = 0;
  for (;;) {
    while (non_zero < n && d[non_zero] == 0) non_zero++;
    if (non_zero == n) break;

    ll temp = non_zero;
    while (temp + 1 < n && sign(d[temp + 1]) == sign(d[non_zero])) temp++;

    FOR(i, non_zero, temp + 1) d[i] += -sign(d[i]);
    ans++;
  }
  cout << ans nl;

  return 0;
}
