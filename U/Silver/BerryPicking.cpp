#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

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

void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

ll mod;
bool cmp(ll a, ll b) { return a % mod > b % mod; }

int main() {
  setIO("berries");

  ll n, k;
  cin >> n >> k;
  vll berries(n);
  ll maxB = 0;
  fo(i, n) {
    cin >> berries[i];
    maxB = max(maxB, berries[i]);
  }

  ll ans = 0;
  for (ll i = 1; i <= maxB; i++) {
    ll baskets = 0;
    for (ll j = 0; j < n; j++)
      baskets += berries[j] / i;

    if (baskets < k / 2)
      continue;

    if (baskets >= k) {
      ans = max(ans, k * i / 2);
      continue;
    }

    mod = i;
    sort(all(berries), cmp);
    ll left = (baskets - k / 2) * i;
    for (ll j = 0; j < n && baskets + j < k; j++)
      left += berries[j] % i;
    ans = max(ans, left);
  }
  cout << ans << endl;

  return 0;
}
