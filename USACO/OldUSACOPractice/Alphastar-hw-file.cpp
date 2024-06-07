#include <iostream>
#include <algorithm>

using namespace std;


struct Bunny {
	bool spot; 
	int w;
};

inline bool compare (Bunny a, Bunny b) { 
	return a.w<b.w;
}

inline int getClosest (int a, int b, int target, Bunny arr[]) {
	if (abs(target-arr[a].w) >= abs(arr[b].w-target)) return b;
	return a;
}


inline bool findAll (int first, Bunny arr[], int n, int target) {
	for (int i = first; i>=0; i--) {
		if (abs(arr[i].w-target) != abs(arr[first].w-target)) break;
		if (arr[i].spot) return true;
	}
	for (int i = first+1; i<n; i++) {
		if (abs(arr[i].w-target) != abs(arr[first].w-target)) break;
		if (arr[i].spot) return true;
	}
	return false;
}

inline bool findClosest (Bunny arr[], int n, int target) {
	if (target <= arr[0].w) return findAll(0, arr, n, target);
	
	if (target >= arr[n-1].w) return findAll(n-1, arr, n, target);

	int low = 0, high = n-1, mid = 0;
	while (low<high) {
		mid = (low+high)/2;
		
		if (arr[mid].w == target) return findAll(mid, arr, n, target) ;

		if (target<arr[mid].w) {
			if (target>arr[mid-1].w) return findAll(getClosest(mid-1, mid, target, arr), arr, n, target);
			high = mid;
		} else {
			if (target<arr[mid+1].w) return findAll(getClosest(mid, mid+1, target, arr), arr, n, target);
			low = mid+1;
		}
	}

	return findAll(mid, arr, n, target);
}
			
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin>>n>>a>>b;
	
	Bunny bunnies[n];
	string temp;
	for (int i = 0; i<n; i++) {
		cin>>temp>>bunnies[i].w;
		if (temp == "S") bunnies[i].spot = true;
		else bunnies[i].spot = false;
	}
	
	sort(bunnies, bunnies + n, compare);
	
	int ans = 0;
	for (int i = a; i<=b; i++) {
		if (findClosest(bunnies, n, i)) 
			ans++;
		/*for (int j = 0; j<close_w.size(); j++) {
			if (bunnies[close_w[j]].spot) {ans++; break;}
		}*/
	}
	cout<<ans<<endl;

	return 0;
}
