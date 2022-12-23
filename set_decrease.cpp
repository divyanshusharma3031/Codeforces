#include<bits/stdc++.h>
using namespace std;
long long accurateFloor(long long a, long long b) {
	long long val = a / b;
	while (val * b > a)
		val--;
	return val;
}
long long solve(long long arr[],long long n,long long k)
{
    sort(arr,arr+n);
    long long s=0;
    vector<long long> pre(n+1,0);
    if(n==1)
    {
        return arr[0]-k;
    }
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+arr[i];
    }
    long long ans=1e18;
    for(int y=0;y<n;y++)
    {
        long long x=arr[0]-accurateFloor(k-pre[n-y]+arr[0],y+1);
        
        ans=min(ans,mpowerax(0LL,x)+y);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        long long k;
        cin>>k;
        long long arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n,k)<<"\n";
    }
    return 0;
}