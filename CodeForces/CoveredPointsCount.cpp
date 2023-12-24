#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
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

  ll n;
  cin >> n;
  map<ll, ll> coord;
  set<ll> points;
  fo(i, n) {
    ll start, end;
    cin >> start >> end;
    coord[start]++;
    coord[end + 1]--;
    points.insert(start);
    points.insert(end + 1);
  }

  ll layers = coord[*points.begin()];
  auto it = next(points.begin());
  vector<ll> ans(n + 1);
  while (it != points.end()) {
    ans[layers] += (*it - *prev(it));
    layers += coord[*it];
    it++;
  }

  for (ll i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  cout << endl;

  return 0;
}
