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
	
	ll n, x; cin>>n>>x;
	vector<pll> nums; 
	fo(i, n) {
		ll a; cin>>a;
		nums.pb(mp(a, i+1));
	}
		
	sort(all(nums));

	fo(i, n) {
		ll left = 0ll;
		ll right = n - 1;
		while (left!=right) {
			if (nums[left].f + nums[right].f + nums[i].f == x && right!=i && left!=i) {
				cout<<nums[left].s<<' '<<nums[right].s<<' '<<nums[i].s<<endl;
				return 0;
			}

			if (nums[left].f + nums[right].f + nums[i].f > x) right--;
			else left++;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;


	return 0;
}
