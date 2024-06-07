//USACO 2016 January Contest, Silver Problem 2. Subsequences Summing to Sevens
//DONE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
using ll = long long;

int main () {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	ll x; ll prefix [n+1]; prefix[0] = 0;
	for (int i = 0; i<n; i++) {
		cin>>x;
		prefix[i+1] = prefix[i]+x;
	}
	ll ans = 0, sum;
	for (int i = 1; i<n; i++) {
		if (i+ans>n) break;
		for (int j = i+1+ans; j<=n; j++) {
			sum = prefix[j]-prefix[i-1];
			if (!(sum%7) && (j-i+1)>ans) ans = j-i+1;
		}
	}
	cout<<ans<<endl;

	return 0;
}
