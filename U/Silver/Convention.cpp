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

ll n, m, c;
vll times;

bool works(ll time) {
  ll cur_cow = 0, bus = 1, start_cow = 0;
  while (cur_cow < n) {
    if (times[cur_cow] - times[start_cow] > time || cur_cow - start_cow + 1 > c) {
      bus++;
      if (bus > m)
        return false;
      start_cow = cur_cow;
    }
    cur_cow++;
  }

  return true;
}

int main() {
  setIO("convention");

  cin >> n >> m >> c;
  times.resize(n);
  FOR(i, 0, n) cin >> times[i];
  srt(times);

  ll lo = 0, high = times[n - 1] - times[0];
  while (lo < high) {
    ll mid = (lo + high) / 2;
    if (works(mid))
      high = mid;
    else
      lo = mid + 1;
  }
  cout << lo nl;

  return 0;
}
