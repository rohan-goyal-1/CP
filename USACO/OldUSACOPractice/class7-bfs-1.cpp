#include <iostream>
#include <queue>

using namespace std;

int main () {
	int n;
	cin>>n;

	int bignum = n*2;

	int dist [bignum];

	for (int i = 0; i<n*2; i++) dist[i] = bignum;

	queue <int> q;
	dist[1] = 0;

	q.push(1);
	
	int currpos;
	int next;
	while (!q.empty()) {
		currpos = q.front();
		q.pop();
		next = currpos - 1;

		if (next>=1 && dist[next]>dist[currpos]+1) {
			dist[next] = dist[currpos]+1;
			q.push(next);
		}

		next = currpos+1;
		if (next<2*n && dist[next]>dist[currpos]+1) {
			dist[next] = dist[currpos] + 1;
			q.push(next);
		}

		next = currpos*3;
		if (next<2*n && dist[next]>dist[currpos]+1) {
			dist[next] = dist[currpos] + 1;
			q.push(next);
		}
	}

	cout<<dist[n];

	return 0;
}
