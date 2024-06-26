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
  ll n;
  cin >> n;
  vll nums(n), sorted(n);;
  FOR(i, 0, n) { cin >> nums[i]; sorted[i] = nums[i]; }

  srt(sorted);

  bool can = true;
  FOR(i, 0, n) {
    bool even = !(nums[i] % 2);
    if (even && sorted[i] % 2 != 0) can = false;
    else if (!even && sorted[i] == 0) can = false;
  }

  if (can) cout << "YES" nl;
  else cout << "NO" nl;
}

int main() {
  setIO("");

  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
