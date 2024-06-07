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
#define loop(i, a, b) for (ll i = a; i < b; i++)
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

vll bales;
ll n, q;

ll search(ll a) {
  ll lo = 0, high = n;
  while (lo < high) {
    ll mid = (high + lo) / 2;
    if (bales[mid] > a)
      high = mid;
    else if (bales[mid] <= a)
      lo = mid + 1;
  }
  return lo;
}

int main() {
  setIO("haybales");

  cin >> n >> q;
  loop(i, 0, n) {
    ll a;
    cin >> a;
    bales.pb(a);
  }
  sort(all(bales));

  while (q--) {
    ll a, b;
    cin >> a >> b;
    cout << search(b) - search(a - 1) nl;
  }

  return 0;
}
