//USACO 2015 December Contest, Silver Problem 3. Breed Counting
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
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q; cin>>n>>q;

	int pG [n+1], pH[n+1], pJ[n+1];
	pG[0] = 0; pH[0] = 0; pJ[0] = 0;
	int x;
	for (int i = 0; i<n; i++) {
		cin>>x;
		pG[i+1] = pG[i]+(x==2 ? 1 : 0);
		pH[i+1] = pH[i]+(x==1 ? 1 : 0);
		pJ[i+1] = pJ[i]+(x==3 ? 1 : 0);
	}
	
	int a, b;
	for (int i = 0; i<q; i++) {
		cin>>a>>b;
		cout<<pH[b]-pH[a-1]<<' '<<pG[b]-pG[a-1]<<' '<<pJ[b]-pJ[a-1]<<endl;
	}

	return 0;
}
