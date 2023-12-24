#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>

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

    ll n; cin>>n;
    vector<pair<pll, ll>> customers(n);
    vll ans(n);
    fo(i, n) {
        cin>>customers[i].f.f>>customers[i].f.s;
        customers[i].s = i;
    }

    sort(all(customers));

    priority_queue<pll> pq;
    ll rooms = 0, last_room = 0;
    fo(i, n) {
        if (pq.empty()) {
			last_room++;
			pq.push(mp(-customers[i].f.s, last_room));
			ans[customers[i].s] = last_room;
		} 
        else {
			pair<ll, ll> minimum = pq.top();
			if (-minimum.f<customers[i].f.f) {
				pq.pop();
				pq.push(mp(-customers[i].f.s, minimum.s));
				ans[customers[i].s] = minimum.s;
			}
			else {
				last_room++;
				pq.push(mp(-customers[i].f.s, last_room));
				ans[customers[i].s] = last_room;
			}
		}
		rooms = max(rooms, ll(pq.size()));
    }
    cout<<rooms<<endl;
    fo(i, n) cout<<ans[i]<<' ';
    cout<<endl;
    
    return 0;
}
