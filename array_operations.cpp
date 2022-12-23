#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n,int k)
{
    int i=0;
    int j=n-1;
    map<int,int> mpp;
    vector<int> v;
    sort(arr,arr+n);
    int ans=0;
    while(j>=0)
    {
        if(i==k)
        {
            break;
        }
        mpp[j]=1;
        v.push_back(arr[j]);
        j--;
        i++;
    }
    i=0;
    int w=v.size()-1;
    sort(v.begin(),v.end());
    while(j>=0)
    {
        if(i==k)
        {
            break;
        }
        ans+=(arr[j]/v[w]);
        i++;
        j--;
        w--;
    }
    while(j>=0)
    {
        ans+=arr[j];
        j--;
    }
    cout<<ans<<"\n";
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
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n,k);
    }
}