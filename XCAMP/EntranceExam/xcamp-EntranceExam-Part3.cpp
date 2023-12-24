#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main () {
	int n, x;
	cin>>n>>x;
	int nums[n];
	for (int i = 0; i<n; i++) cin>>nums[i];
	
	int front = 0; int end = 0; int sum = 0; int ans = 0;
	while (true) {
		if (sum<x) {
			sum+=nums[end];
			end++;
		}
		if (sum>x) {
			sum-=nums[front];
			front++;
		}
		if (sum == x) {
			ans++;
			sum-=nums[front];
			front++;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
