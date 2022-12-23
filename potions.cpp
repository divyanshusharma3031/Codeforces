#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

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
ll dpapproach(ll i,ll n,vi &arr,map<pair<ll,ll>,ll> &dp,ll health)
{
    if(i==n)
    {
        return 0;
    }
    if(health<0)
    {
        return 0;
    }
    if(dp[{i,health}]!=0)
    {
        return dp[{i,health}];
    }
    if((health+arr[i])<0)
    {
        return dp[{i,health}]=dpapproach(i+1,n,arr,dp,health);
    }
    if(arr[i]<0)
    {
        return dp[{i,health}]=max(1+dpapproach(i+1,n,arr,dp,health+arr[i]),dpapproach(i+1,n,arr,dp,health));
    }
    return dp[{i,health}]=1+dpapproach(i+1,n,arr,dp,health+arr[i]);
}
void solve()
{
    ll n;
    cin>>n;
    vi arr(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<pair<ll,ll>,ll> dp;
    ll health=0;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}