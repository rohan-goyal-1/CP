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

  ll n;
  cin >> n;

  multiset<ll> towers;
  ll x;
  fo(i, n) {
    cin >> x;
    auto it = towers.upper_bound(x);
    if (it == towers.end())
      towers.insert(x);
    else {
      towers.erase(it);
      towers.insert(x);
    }
  }
  cout << towers.size() << endl;

  return 0;
}
