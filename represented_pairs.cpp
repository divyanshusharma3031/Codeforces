#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n)
{
    vector<int> pre(n,0);
    pre[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        
    }
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