#include <bits/stdc++.h>
using namespace std;


int main() {

  long long num;
    cin >> num;
  long long arr[num];

  for (int i = 0; i < num; i++)
    {
      cin >> arr[i];
    }
  long long n = sizeof(arr)/sizeof(arr[0]);

  sort(arr, arr + n);
  // for (int i = 0; i < n; i++)
  //       cout << arr[i] << " ";
  long long sum[num];
  long long max[num];
  // cout << endl;
  for (int i = 0; i < num; i++)
    {
      sum[i]=arr[i]*(num-(i));
    }
  long long greatest = sum[0];
  for (int i = 0 ; i < num; i++)
    {
      if (sum[i]>greatest)
        greatest = sum[i];
    }
    vector<long long> v;
    for (int i = 0; i < num; i++)
      {
        if (sum[i]==greatest)
        {
          v.push_back(arr[i]);
        }
      }

    long long leastfinal = v[0];

  // for (int i = 0; i < v.size(); i++)
  //   cout << v[i] << " ";

  for (int i = 0; i < v.size(); i++)
    {
      if (leastfinal>v[i])
        leastfinal = v[i];
    }

  cout << greatest << " " << leastfinal << endl;
  
}

/*
 * #include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main () {
	int n;

	cin>>n;
	int costs [n];

	for (int i = 0; i<n; i++) 
		cin>>costs[i];
	
	sort(costs, costs+n);
	pair <int, int> max;
	pair <int, int> curr;
	
	curr.first = curr.second = max.first = max.second = 0;

	for (int i = 0; i<n; i++) {
		curr.second+=(costs[curr.first]*(n-curr.first));
		if (curr.second>max.second){ 
			max.second = curr.second;
			max.first = curr.first;
		}
		curr.second = 0;
		curr.first++;
	}
	cout<<max.second<<" "<<costs[max.first];
}

*/
	/*long long curr_cost = 0;
	long long sum =	0;
	long long max_sum = 0;
	long long max_cost = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (costs[j] >= costs[curr_cost]) 
				sum+=costs[curr_cost];
		}
		if (sum>max_sum) {
			max_sum = sum;
			max_cost = curr_cost;
		}
		if (sum == max_sum) 
			if (costs[curr_cost]<costs[max_cost]) max_cost = curr_cost;
		curr_cost++;
		//cout<<"cost index: "<<curr_cost-1<<endl;
		//cout<<sum<<endl;
		sum = 0;
	}*/
