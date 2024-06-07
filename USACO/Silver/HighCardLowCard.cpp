#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
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

ll solve(vector<ll> elsie, vector<ll> bessie, const function<bool(int, int)> &cmp) {
  sort(all(elsie), cmp), sort(all(bessie), cmp);
  ll n = bessie.size();

  ll ret = 0, ind = 0;
  fo(i, n) {
    if (cmp(bessie[ind], elsie[i])) {
      ret++;
      ind++;
    }
  }

  return ret;
}

int main() {
  setIO("cardgame");

  ll n;
  cin >> n;
  map<ll, bool> elsies;
  vll elsie1, bessie1, elsie2, bessie2;
  fo(i, n) {
    ll temp;
    cin >> temp;
    elsies[temp] = 1;

    if (i < n / 2)
      elsie1.pb(temp);
    else
      elsie2.pb(temp);
  }

  fo(i, n * 2) {
    if (!elsies.count(i + 1)) {
      if (bessie2.size() < n / 2)
        bessie2.pb(i + 1);
      else
        bessie1.pb(i + 1);
    }
  }

  ll ans = 0;
  ans += solve(elsie1, bessie1, greater<ll>());
  ans += solve(elsie2, bessie2, less<ll>());

  cout << ans << endl;

  return 0;
}
