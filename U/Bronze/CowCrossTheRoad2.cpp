// USACO 2017 February Contest, Bronze
// Problem 2. Why Did the Cow Cross the Road II
// DONE
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

char str[52];
map<char, pair<int, int>> indices;
int ans = 0;

void checkInter(char a) {
  int counts[26];
  fill(counts, counts + 26, 0);

  for (int i = indices.at(a).first + 1; i < indices.at(a).second; i++) {
    i %= 52;
    if (int(str[i]) - 65 < int(a - 65))
      continue;
    if (counts[int(str[i]) - 65] == 1)
      ans--;
    else {
      ans++;
      counts[int(str[i]) - 65]++;
    }
  }
}
int main() {
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 26; i++)
    indices[char(i + 65)] = make_pair(-1, -1);

  for (int i = 0; i < 52; i++) {
    cin >> str[i];
    if (indices.at(str[i]).first == -1)
      indices.at(str[i]).first = i;
    else
      indices.at(str[i]).second = i;
  }

  for (int i = 0; i < 26; i++)
    checkInter(char(i + 65));

  cout << ans << endl;

  return 0;
}
