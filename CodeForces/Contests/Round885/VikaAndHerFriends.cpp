#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define fo(i, n) for (ll i = 0; i < n; i++)
#define endl '\n'
using ll = long long;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair

using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)

inline void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

bool canEscape(ll n, ll m, ll k, ll x, ll y) {
  bool ret = true;

  for (ll i = 0; i < k; i++) {
    ll xi, yi;
    cin >> xi >> yi;

    ll dx = abs(x - xi);
    ll dy = abs(y - yi);

    if ((dx + dy) % 2 == 0)
      ret = false;
  }

  return ret;
}

int main() {
  setIO();

  ll t;
  cin >> t;

  while (t--) {
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

    if (canEscape(n, m, k, x, y))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
