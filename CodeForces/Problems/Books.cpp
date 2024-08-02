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
	
	int n, t; cin>>n>>t;
	int times[n]; fo(i, n) cin>>times[i];

	ll currSum = 0ll, ans = 0ll; int left = 0, right = 0;
	while (right<n && left<n) {
		while (right<n) {
			currSum+=times[right++];
			if (currSum>t) {
				currSum-=times[--right];
				break;
			}
		}
		ans = max(ans, (ll)right-left);
		currSum-=times[left++];
	}
	cout<<ans<<endl;
	return 0;
}
