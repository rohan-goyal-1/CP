#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
using ll = long long;

struct Mountain {
	ll start, end;
};
bool cmp (Mountain a, Mountain b) { 
	if (a.start == b.start) return a.end>b.end;
	return a.start<b.start;
}

int main () {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin>>n;
	Mountain mounts[n]; 
	int x, y; 
	for (ll i = 0; i<n; i++) {
		cin>>x>>y;
		mounts[i].start = x-y; mounts[i].end = x+y;
	}
	
	sort(mounts, mounts+n, cmp);
	
	ll ans = 0ll;
	ll right = -1ll;
	for (int i = 0; i<n; i++) {
		if (mounts[i].end>right) {
			ans++;
			right = mounts[i].end;
		}
	}
	cout<<ans<<endl;

	return 0;
}
