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
	ll P[n+1]; P[0] = 0;
	ll H[n+1]; H[0] = 0;
	ll S[n+1]; S[0] = 0;
	char temp;
	fo(i, n) {
		cin>>temp;
		P[i+1] = P[i] + (temp == 'P');
		H[i+1] = H[i] + (temp == 'H');
		S[i+1] = S[i] + (temp == 'S');
	}
	
	ll ans = 0;
	for (ll i = 1; i<=n; i++) {
		//Hoof to Paper
		ans = max(ans, S[i-1] + H[n]-H[i-1]);
		//Hoof to Scissor
		ans = max(ans, S[i-1] + P[n]-P[i-1]);
		//Scissor to Paper
		ans = max(ans, P[i-1] + H[n]-H[i-1]);
		//Scissor to Hoof
		ans = max(ans, P[i-1] + S[n]-S[i-1]);
		//Paper to Hoof
		ans = max(ans, H[i-1] + S[n]-S[i-1]);
		//Paper to Scissor
		ans = max(ans, H[i-1] + P[n]-P[i-1]);
	}
	cout<<ans<<endl;

	return 0;
}
