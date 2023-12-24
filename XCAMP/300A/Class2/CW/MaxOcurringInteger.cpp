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
	
	ll n, m; cin>>n>>m;
	ll L[n], R[n]; fo(i, n) cin>>L[i]>>R[i];
	ll track[m]; fill(track, track+m, 0);

	fo(i, n) {
		track[L[i]-1]++;
		track[R[i]-1]--;
	}
	
	ll ans = 0;
	ll prefix[m+1]; prefix[0] = 0;
	fo(i, m) {
		prefix[i+1] = prefix[i]+track[i];
		if (prefix[i+1]>prefix[ans+1]) ans = i;
	}
	cout<<++ans<<endl;

	return 0;
}
