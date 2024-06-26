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

void solve() {
  ll n, k;
  cin >> n >> k;
  ll planks[n];
  fo(i, n) cin >> planks[i];

  ll last_seen[k];
  fo(i, n) {
    last_seen[planks[i]] = i;
  }
}

int main() {
  setIO();

  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
