#include <bits/stdc++.h>
using namespace std;
long long solve(int arr[],int n,int k)
{
    vector<long long> nums;
    int i=0;
    while(k)
    {
        nums.push_back(arr[i]);
        i++;
        if(i==n)
        {
            i=0;
            k--;
        }
    }
  long long globalMaxSum = nums[0], currMaxSum = nums[0];
        for (int ind = 1; ind < nums.size(); ind++) {
            currMaxSum = max(currMaxSum + nums[ind], nums[ind]);
            globalMaxSum = max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<solve(arr,n,k)<<'\n';
	}
	return 0;
}

