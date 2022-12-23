#include<bits/stdc++.h>
using namespace std;
long long solve(long long arr[],int n)
{
    
    long long mx=arr[0];
    long long mn=arr[0];
    for(int i=0;i<n;i++)
    {
        mx=max(arr[i],mx);
        mn=min(arr[i],mn);
    }
    return mx-mn;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<'\n';
    }
}