#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <iterator>

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
	ll m; cin>>m;
	multiset<ll> prices; 
	fo(i, n) {
		ll x; cin>>x;
		prices.insert(x);
	}

	fo(i, m) {
		ll x; cin>>x;
		auto it = prices.upper_bound(x);
		if (it == prices.begin()) cout<<-1<<endl;
		else {
			cout<<*(--it)<<endl;
			prices.erase(it);
		}
	}

	return 0;
}
