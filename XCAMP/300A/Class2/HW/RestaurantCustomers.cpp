#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define fo(i, n) for (int i = 0; i<n; i++)
#define endl '\n'
using ll = long long;

using pi = pair<int,int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair

using vi = vector<int>; 
using vll = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)

void setIO (string input = "") {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	if (input.size()) {
		freopen((input+".in").c_str(), "r", stdin);
		freopen((input+".out").c_str(), "w", stdout);
	}
}

int main () {
	setIO();	
	
	ll n; cin>>n;
	vector<pll> events;
	ll a, b;
	fo(i, n) {
		cin>>a>>b;
		events.pb(mp(a, 1));
		events.pb(mp(b, -1));
	}

	sort(all(events));
	
	ll temp = 0, ans = 0;
	for (pi e : events) {
		temp += e.s;
		ans = max(ans, temp);
	}
	cout<<ans<<endl;

	return 0;
}
