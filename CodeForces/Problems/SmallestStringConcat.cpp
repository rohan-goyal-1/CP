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

bool cmp (string a, string b) {
	return a+b<b+a;
}

int main () {
	setIO();	
	
	int n; cin>>n;
	string words[n]; fo(i, n) cin>>words[i];
	
	sort(words, words+n, cmp);

	for (string word : words) cout<<word;
	cout<<endl;

	return 0;
}
