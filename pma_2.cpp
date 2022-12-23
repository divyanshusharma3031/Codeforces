#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void reverse(int lo,int hi,vector<int> &arr)
{
    while(lo<=hi)
    {
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}

void solve(vector<ll> &arr,ll n)
{
    int oddidx=-1;
    int evenidx=-1;
    int e=INT_MAX;
    int o=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if((i % 2)==0)
        {
            if(arr[i]<e)
            {
                e=arr[i];
                // cout<<e<<" ";
                evenidx=i;
            }
        }
        else
        {
            if(arr[i]>o)
            {
                o=arr[i];
                // cout<<o<<"\n";
                oddidx=i;
            }
        }
    }
    if(arr[evenidx]<arr[oddidx])
    {
        int x=arr[e];
        arr[evenidx]=o;
        arr[oddidx]=e;
    }

   ll ans=0;

    for(int i=0;i<n;i++)
    {
        if((i%2)==0)
        {
            ans+=arr[i];
        }
        else
        {
            ans-=arr[i];
        }
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
        ll n;
        cin>>n;
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i]=abs(arr[i]);
            // cout<<arr[i]<<"\n";
        }
        solve(arr, n);
    }
}
