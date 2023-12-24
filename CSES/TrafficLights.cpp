#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
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
    
    ll x, n; cin>>x>>n;
    set<ll> lights {0, x}; 
    multiset<ll> gaps {x};
    fo(i, n) {
        ll pos; cin>>pos;
        
        auto it1 = lights.upper_bound(pos);
        auto it2 = it1; it2--;

        gaps.erase(gaps.find(*it1-*it2));
        gaps.insert(*it1-pos);
        gaps.insert(pos-*it2);
        lights.insert(pos);

        auto ans = gaps.end();
        cout<<*--ans<<' ';
    }
    cout<<endl;

    return 0;
}
