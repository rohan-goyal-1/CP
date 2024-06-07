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

struct Cow {
	ll x, y, id;
	Cow (ll x, ll y, ll id) {
		this->x = x;
		this->y = y;
		this->id = id;
	}
};


bool cmp1 (const Cow& a, const Cow& b) {
	if (a.x == b.x) return a.y<b.y;
	return a.x<b.x;
}

bool cmp2 (const Cow& a, const Cow& b) {
	if (a.y == b.y) return a.x<b.x;
	return a.y<b.y;
}

int main () {
	setIO();	
	
	ll n; cin>>n;
	vector<Cow> cowsN;
	vector<Cow> cowsE;
	char dir; ll x, y;
	fo(i, n) {
		cin>>dir>>x>>y;
		if (dir == 'N') cowsN.pb(Cow(x, y, i));
		else cowsE.pb(Cow(x, y, i));
	}

	sort(all(cowsN), cmp1);
	sort(all(cowsE), cmp2);
	
	vll blame(n, 0);
	vector<bool> stopped(n, false); 
	for (auto e : cowsE) {
		for (auto n : cowsN) {
			if (!stopped[e.id] && !stopped[n.id] && e.y>=n.y && e.x<=n.x) {
				ll xlen = n.x-e.x;
				ll ylen = e.y-n.y;
				if (ylen<xlen) {
					blame[n.id] += (1 + blame[e.id]);
					stopped[e.id] = true;
				}
				if (ylen>xlen){
					blame[e.id] += (1 + blame[n.id]);
					stopped[n.id] = true;
				}
			}
		}
	}

	fo(i, n) cout<<blame[i]<<endl;	

	return 0;
}
