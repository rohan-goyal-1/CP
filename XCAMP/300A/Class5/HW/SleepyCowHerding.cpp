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

int main() {
  setIO("");

  ll n;
  cin >> n;
  vll cows(n);
  FOR(i, 0, n) cin >> cows[i];

  srt(cows);

  ll min_moves = INT_MAX;
  if ((cows[n - 2] - cows[0] == n - 2 && cows[n - 1] - cows[n - 2] > 2) || (cows[n - 1] - cows[1] == n - 2 && cows[1] - cows[0] > 2)) min_moves = 2;
  else {
    ll farthest = 0;
    FOR(curr, 0, n) {
      while (farthest < n - 1 && cows[farthest + 1] - cows[curr] < n) farthest++;
      min_moves = min(min_moves, n - (farthest - curr + 1));
    }
  }
  cout << min_moves << endl;

  ll gap = 0;
  FOR(i, 0, n-1) gap += cows[i + 1] - cows[i] - 1;
  ll max_moves = max(gap - (cows[1] - cows[0] - 1), gap - (cows[n - 1] - cows[n - 2] - 1));
  cout << max_moves << endl;

  return 0;
}
