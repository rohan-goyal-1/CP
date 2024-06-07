#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
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

struct Entry {
  ll day, id, update;
  bool operator<(const Entry &a) const { return day < a.day; }
  Entry(ll day, ll id, ll update) : day(day), id(id), update(update) {}
};

int main() {
  setIO("measurement");

  ll n, g;
  cin >> n >> g;
  vector<Entry> entries;
  map<ll, ll> cows;
  fo(i, n) {
    ll day, id, update;
    cin >> day >> id >> update;
    entries.pb(Entry(day, id, update));
    cows[id] = g;
  }

  sort(all(entries));

  ll ans = 0;
  map<ll, ll> prod{{g, n}};
  for (auto e : entries) {
    ll amt = cows[e.id];
    bool was_top = amt == prod.rbegin()->first;
    ll prev = prod[amt]--;
    if (!prod[amt])
      prod.erase(amt);

    amt += e.update;
    cows[e.id] = amt;
    prod[amt]++;

    ll curr = prod[amt];
    bool is_top = amt == prod.rbegin()->first;

    if (was_top && is_top && prev == curr)
      continue;
    if (was_top || is_top)
      ans++;
  }
  cout << ans << endl;

  return 0;
}
