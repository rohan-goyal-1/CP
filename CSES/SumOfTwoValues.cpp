#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>

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
	
	ll n, x; cin>>n>>x;
	ll nums[n]; 
	for (int i = 0; i<n; i++) 
		cin>>nums[i];

	map<int, int> ind;
	for (int i = 0; i<n; i++) {
		if (ind.count(x-nums[i])) {
			cout<<i+1<<' '<<ind[x-nums[i]]<<endl;
			return 0;
		}
		ind[nums[i]] = i+1;
	}
	cout<<"IMPOSSIBLE"<<endl;

	return 0;
}
