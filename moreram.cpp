#include<bits/stdc++.h>
using namespace std;\
void solve(int a[],int b[],int n,int k)
{
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back({a[i],b[i]});
    }
    sort(arr.begin(),arr.end());
    int f=k;
    for(int i=0;i<n;i++)
    {
        if(arr[i].first>f)
        {
            break;
        }
        else
        {
            f+=arr[i].second;
        }
    }
    cout<<f<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[n];
        int arr2[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }
        solve(arr,arr2,n,k);
    }
}