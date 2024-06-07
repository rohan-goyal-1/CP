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

ll n, t;
vll cows;
ll calc_t(ll k) {
  ll index = 0;
  priority_queue<ll> stage;
  for (index = 0; index < n && index < k; index++)
    stage.push(-cows[index]);

  ll time = 0;
  while (stage.size()) {
    time += max(0, -stage.top() - time);
    stage.pop();
    if (index < n) {
      stage.push(-(cows[index] + time));
      index++;
    }
  }

  return time;
}

int main() {
  setIO("cowdance");

  cin >> n >> t;
  cows.resize(n);
  FOR(i, 0, n) cin >> cows[i];

  ll lo = 1, high = n, ans = n;
  while (lo <= high) {
    ll mid = (high + lo) / 2;
    if (calc_t(mid) <= t) {
      ans = min(ans, mid);
      high = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ans nl;

  return 0;
}
