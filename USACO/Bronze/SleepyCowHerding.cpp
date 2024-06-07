//USACO 2019 February Contest, Bronze Problem 1. Sleepy Cow Herding
//DONE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

int main () {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cows[3]; cin>>cows[0]>>cows[1]>>cows[2];
	sort(cows, cows+3);

	int diff1 = cows[2]-cows[1]-1; int diff2 = cows[1]-cows[0]-1;
	int minDiff;
	if (diff1 == 0) {
		minDiff = diff2;
	} 
	else if (diff2 == 0) {
		minDiff = diff1;
	}
	else {
		minDiff = min(diff1, diff2);
	}
	if (diff1 == 0 && diff2 == 0) cout<<0<<endl;
	else cout<<((minDiff>1) ? 2 : 1)<<endl;
	cout<<max(diff1, diff2)<<endl;
	
	return 0;
}
