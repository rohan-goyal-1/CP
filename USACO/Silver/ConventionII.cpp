#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
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

struct Cow {
  ll sen, start, duration;

  bool operator<(const Cow &a) const { return sen < a.sen; }
};

bool cmp(const Cow &a, const Cow &b) { return a.start < b.start; }

int main() {
  setIO("convention2");

  ll n;
  cin >> n;
  vector<Cow> cows;
  fo(i, n) {
    ll a, t;
    cin >> a >> t;
    cows.push_back({i, a, t});
  }
  sort(all(cows), cmp);

  set<Cow> waiting;
  ll longest_time = 0, time = 0;
  for (ll curr = 0; curr < n || !waiting.empty(); curr++) {
    if (curr < n && cows[curr].start <= time)
      waiting.insert(cows[curr]);
    else if (waiting.empty())
      time = cows[curr].start + cows[curr].duration;
    else {
      Cow next = *waiting.begin();
      longest_time = max(longest_time, time - next.start);
      time += next.duration;
      waiting.erase(waiting.begin());
      curr--;
    }
  }
  cout << longest_time << endl;

  return 0;
}
