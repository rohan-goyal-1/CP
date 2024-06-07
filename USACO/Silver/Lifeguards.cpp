#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define endl '\n'
using ll = long long;

struct Event {
	int time, id;
	bool start;
	Event (int time, int id, bool start) {
		this->time = time;
		this->id = id;
		this->start = start;
	}
};
bool cmp (const Event &a, const Event &b) { return a.time<b.time; }

int main () {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	int start, end;
	vector<Event> events;
	for (int i = 0; i<n; i++) {
		cin>>start>>end;
		events.push_back(Event(start, i, 1));
		events.push_back(Event(end, i, 0));
	}
	sort(events.begin(), events.end(), cmp);

	int aloneTime[n]; fill(aloneTime, aloneTime+n, 0);
	set<int> active;
	int prev = 0, ans = 0, curr;
	for (auto e : events) {
		curr = e.time;

		if (active.size()>0) ans+=curr - prev;
		if (active.size() == 1) aloneTime[*active.begin()] += curr-prev;

		if (e.start) active.insert(e.id);
		else active.erase(e.id);

		prev = curr;
	}
	cout<<ans-*min_element(aloneTime, aloneTime+n)<<endl;
	
	return 0;
}
