#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n)
{
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    int ans=0;
    for(auto i=mpp.begin();i!=mpp.end();i++)
    {
        if((i->second)>1 && i->first!=0 && mpp.find(-(i->first))==mpp.end())
        {
            ans+=2;
        }
        else
        {
            ans+=1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<'\n';
    }
}