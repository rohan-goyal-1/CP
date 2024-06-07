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

int main() {
  setIO("highcard");

  ll n;
  cin >> n;
  bool elsies[n * 2];
  fo(i, n) {
    ll temp;
    cin >> temp;
    elsies[--temp] = 1;
  }

  vll bessie;
  vll elsie;
  fo(i, n * 2) {
    if (elsies[i])
      elsie.pb(i + 1);
    else
      bessie.pb(i + 1);
  }

  ll e = 0, b = 0, ans = 0;
  while (e < n && b < n) {
    if (bessie[b] > elsie[e])
      ans++, e++, b++;
    else
      b++;
  }
  cout << ans << endl;

  return 0;
}
