#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll arr[],ll n,ll mid,ll h)
{
    ll attack=0;
    for(ll i=0;i<n-1;i++)
    {
        if((arr[i+1]-arr[i])>=mid)
        {
            attack+=mid;
        }
        else
        {
            attack+=(arr[i+1]-arr[i]);
        }
    }
    attack+=mid;
    if(attack>=h)
    {
        return true;
    }
    return false;
}
void solve(ll arr[], ll n, ll h)
{
    ll low=1;
    ll hi=h;
    ll ans=1;
    while(low<=hi)
    {
        ll mid=low+(hi-low)/2;
        if(check(arr,n,mid,h))
        {
        // cout<<mid<<"\n";
            ans=mid;
            hi=mid-1;
        }
        else
        {
            low=mid+1;
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
    while (t--)
    {
        ll n;
        ll h;
        cin >> n >> h;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n, h);
    }
}