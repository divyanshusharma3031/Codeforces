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

void reverse(int lo, int hi, vector<int> &arr)
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
    int i = 0;
    int n = s.length() - 1;
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

void solve()
{
    ll n;
    ll x;
    cin>>n>>x;
    vi arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    map<ll,ll> mpp;
    map<int,set<int>> idx;
    map<int,int> vis;
    for(ll i=0;i<n;i++)
    {
        mpp[arr[i]]++;
        idx[arr[i]].insert(i);
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(vis[i])
        {
            continue;
        }
        if(mpp[x*arr[i]])
        {
            mpp[x*arr[i]]--;
            vis[*idx[x*arr[i]].begin()]=1;
            // cout<<i<<" "<<(*idx[x*arr[i]].begin())<<" ";
            idx[x*arr[i]].erase(*idx[x*arr[i]].begin());
        }
        else
        {
            // cout<<i<<"\n";
            ans++;
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
        solve();
    }
}