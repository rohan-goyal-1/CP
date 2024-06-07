#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
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

void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

ll n;
vector<vll> pfx_more;
vector<vll> pfx_less;
vector<pll> cows;

void pfx() {
  fo(i, n) {
    fo(j, n) {
      pfx_more[i][j + 1] = pfx_more[i][j] + (cows[j].s > cows[i].s);
      pfx_less[i][j + 1] = pfx_less[i][j] + (cows[j].s < cows[i].s);
    }
  }
}

ll solve() {
  ll ans = 0;
  fo(i, n) {
    for (ll j = i + 1; j < n; j++) {
      ans++;
      ll a, b;
      if (cows[j].s > cows[i].s) {
        a = pfx_more[j][j + 1] - pfx_more[j][i + 1];
        b = pfx_less[i][j + 1] - pfx_less[i][i + 1];
      }
      else {
        a = pfx_less[j][j + 1] - pfx_less[j][i + 1];
        b = pfx_more[i][j + 1] - pfx_more[i][i + 1];
      }
      ans += a + b + (a * b);
    }
  }
  return ans;
}

int main() {
  setIO();

  cin >> n;
  cows.resize(n);
  pfx_more.resize(n, vector<ll>(n + 1));
  pfx_less.resize(n, vector<ll>(n + 1));

  fo(i, n) cin >> cows[i].f >> cows[i].s;
  sort(all(cows));

  pfx();

  cout << solve() + n + 1 << endl;

  return 0;
}
