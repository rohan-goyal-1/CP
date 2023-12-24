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
#define For(i, b) FOR(i, 0, b)
#define endl '\n'
#define sp << ' ' <<
#define nl << '\n'
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

#ifdef LOCAL
#include "dbg.h"
#else 
#define dbg(...) 
#define dbgm(...) 
#endif

#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

inline void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

int main() {
  #ifndef LOCAL
  setIO("");
  #else
  fastIO;
  #endif

  ll n, m;
  cin >> n >> m;
  priority_queue<ll> mice, holes;
  For(i, n) {
    ll a; cin >> a;
    mice.push(a);
  }
  For(i, m) {
    ll a; cin >> a;
    holes.push(a);
  }

  ll dist = 0;
  while (!mice.empty()) {
    if (holes.top() <= mice.top()) {
      dist += mice.top() - holes.top();
      mice.pop(), holes.pop();
    }
    else holes.pop();
  }
  cout << dist nl;

  return 0;
}
