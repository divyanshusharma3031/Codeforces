#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

void reverse(ll lo, ll hi, vector<ll> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    ll i = 0;
    ll n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}
bool compare(pair<ll,ll> p1,pair<ll,ll> p2)
{
    return (p1.second-p1.first)<(p2.second-p2.first);
}
void solve()
{
    ll n;
    
    ll k;
    
    cin>>n>>k;
    
    vector<ll> arr(n,0);

    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    map<ll,ll> mpp;
    
    for(ll i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    set<ll> s;
    for(ll i=0;i<n;i++)
    {
        if(mpp[arr[i]]>=k)
        {
            s.insert(arr[i]);
        }
    }
    ll lo=*s.begin();
    ll hi=lo;
    ll ans=INT_MIN;
    vector<pair<ll,ll>> v;
    for(auto it:s)
    {
        ll x=*s.upper_bound(it);
        if(s.upper_bound(it)!=s.end() && x==(it+1))
        {
            hi=x;
        }
        else
        {
            ans=max(ans,hi-lo);
            // cout<<lo<<" "<<hi<<"\n";
            v.push_back({lo,hi});
            lo=x;
        }
    }
    if(ans==INT_MIN)
    {
        cout<<"-1\n";
        return;
    }
    sort(v.begin(),v.end(),compare);
    cout<<v[v.size()-1].first<<" "<<v[v.size()-1].second<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}