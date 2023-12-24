#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
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

int main() {
  setIO();

  ll n, k;
  cin >> n >> k;

  vector<pll> movies(n);
  fo(i, n) cin >> movies[i].s >> movies[i].f;

  sort(all(movies));

  ll ans = 0;
  multiset<ll> ends;
  fo(i, k) ends.insert(0);

  fo(i, n) {
    auto it = ends.upper_bound(movies[i].s);
    if (it == ends.begin())
      continue;
    ends.erase(--it);
    ends.insert(movies[i].f);
    ans++;
  }
  cout << ans << endl;

  return 0;
}
