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

  ll a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<pll> mouse(m);
  fo(i, m) {
    string temp;
    cin >> mouse[i].f >> temp;
    if (temp == "USB")
      mouse[i].s = 0;
    else
      mouse[i].s = 1;
  }

  sort(all(mouse));

  ll tot = 0, price = 0;
  for (pll i : mouse) {
    if (i.s) {
      if (b)
        b--, tot++, price += i.f;
      else if (c)
        c--, tot++, price += i.f;
    }
    else {
      if (a)
        a--, tot++, price += i.f;
      else if (c)
        c--, tot++, price += i.f;
    }
  }
  cout << tot << ' ' << price << endl;

  return 0;
}
