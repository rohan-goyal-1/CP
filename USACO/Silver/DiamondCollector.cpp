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
	setIO("diamond");	
	
	ll n, k; cin>>n>>k;
	vll sizes(n); fo(i, n) cin>>sizes[i];

	sort(all(sizes));

	vll compat;
	ll right = 0; 
	fo(left, n) {
		while (right<n && sizes[right]-sizes[left]<=k) right++; 
		compat.pb(right-left);
	}
	
	vll maxVal(n+1);
	maxVal[n] = 0;
	for (ll i = n-1; i>=0; i--) maxVal[i] = max(maxVal[i+1], compat[i]);


	ll ans = 0;
	fo(i, n) ans = max(ans, compat[i] + maxVal[i + compat[i]]);
	
	cout<<ans<<endl;

	return 0;
}
