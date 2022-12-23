#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void reverse(int lo,int hi,int arr[])
{
    while(lo<=hi)
    {
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}
void solve(long long arr[],int n)
{
    long long pre[n]={0};
    pre[0]=arr[0];
    long long su=0;
    su+=arr[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+arr[i];
        su+=arr[i];
    }
    // reverse(0,n-1,arr);
    long long mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        mn=min(mn,max(pre[i],su-pre[i]));
    }
    cout<<mn<<"\n";
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
        int k;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}
