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

void solve(ll n,ll b,ll x,ll y)
{
    vector<ll> arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if((arr[i-1]+x)<=b)
        {
            arr[i]=arr[i-1]+x;
        }
        else
        {
            arr[i]=arr[i-1]-y;
        }
    }
    ll s=0;
    for(int i=0;i<=n;i++)
    {
        s+=arr[i];
    }
    cout<<s<<"\n";
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
        ll b;
        cin>>b;
        ll x;
        ll y;
        cin>>x>>y;
        solve(n,b,x,y);
    }
}
