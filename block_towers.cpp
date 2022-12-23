#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n,ll m)
{
    vector<ll> inventory;
    inventory.push_back(1);
    ll i=0;
    ll h=0;
    ll c=0;
    while(i<m)
    {
        ll x=inventory[0];
        inventory.pop_back();
        h+=x;
        ll y=0;
        // cout<<h<<"\n";
        ll w=0;
        if(h>=n)
        {
            break;
            x=n-x;
            y=x;
            w=h;
            h=0;
            c++;
        }
        inventory.push_back(y+h+w);
        i++;
    }
    cout<<m-i<<"\n";
    cout<<m-i+c<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        ll x;
        ll m;
        cin>>x;
        cin>>m;
        solve(x,m);
    }
}