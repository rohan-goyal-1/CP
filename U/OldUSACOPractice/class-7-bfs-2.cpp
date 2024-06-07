#include <iostream>
#include <queue>
using namespace std;

int main () {
	int a, b, n, p;
	cin>>a>>b>>n>>p;

	int colors[n];

	for (int i = 0; i<n; i++) 
		cin>>colors[i];

	int dist [p+1];

	for (int i = 0; i<n; i++) 
		dist[i] = INT_MAX;

	queue q;

	dist[a] = 0;

	q.push(a);

	while (!q.empty()) {

	return 0;
}
