#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <limits.h>

using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
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

int main() {
  setIO();

  ll k, m, n;
  cin >> k >> m >> n;
  m++;
  vector<pll> grass(k);
  fo(i, k) cin >> grass[i].f >> grass[i].s;

  vll nhoj(m);
  fo(i, m-1) cin >> nhoj[i];
  nhoj[m-1] = LONG_MAX;

  sort(all(grass)), sort(all(nhoj));

  vll benefit;
  ll l = 0, r = 0;
  fo(i, m) {
    ll dist;
    if (!i)
      dist = LONG_MAX;
    else
      dist = nhoj[i] - nhoj[i - 1];

    ll cur = 0, tot = 0, max_half = 0;
    while (r < k && grass[r].f < nhoj[i]) {
      cur += grass[r].s, tot += grass[r].s;
      while (grass[r].f - grass[l].f >= dist / 2) {
        cur -= grass[l].s;
        l++;
      }
      max_half = max(max_half, cur);
      r++;
    }
    l = r;
    benefit.pb(max_half), benefit.pb(tot - max_half);
  }
  ll ans = 0;
  sort(all(benefit), greater<ll>());
  fo(i, n) ans += benefit[i];
  cout << ans << endl;

  return 0;
}
