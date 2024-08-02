#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <limits.h>
#include <set>

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
	vll cities(n); 
	fo(i, n) cin>>cities[i];
	
	set<ll> towers; 
    ll tower;
	fo(i, m) {
        cin>>tower;
        towers.insert(tower);
    }
    
    ll ans = 0;
    fo(i, n) {
        ll dist = INT_MAX;
        auto closest = towers.lower_bound(cities[i]);

        if (closest != towers.end())
            dist = *closest-cities[i];
        if (closest != towers.begin()) {
            closest--;
            dist = min(dist, cities[i]-*closest);
        }
        ans = max(ans, dist);
    }
    cout<<ans<<endl;

	return 0;
}
