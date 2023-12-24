#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

#define endl '\n'
using ll = long long;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin>>n;
	ll nums[n]; for (ll i = 0; i<n; i++) cin>>nums[i];

	ll sum = 0, ans = INT_MIN;
	for (ll i = 0; i<n; i++) {
		sum = sum + nums[i];
		ans = max(ans, sum);
		sum = max(0ll, sum);
	}
	cout<<ans<<endl;
	
	return 0;
}
