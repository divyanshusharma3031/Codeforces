#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
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

void solve()
{
    ll n;

    ll m;

    cin >> n >> m;

    vector<vector<ll>> arr(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    map<ll,vi> mppx;
    map<ll,vi> mppy;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            mppx[arr[i][j]].push_back(i);
            mppy[arr[i][j]].push_back(j);
        }
    }
    for(auto it:mppx)
    {
        sort(it.second.begin(),it.second.end());
        for(ll i=0;i<it.second.size();i++)
        {
            ans=ans+(2*i+1-it.second.size())*(it.second[i]);
        }
    }
    for(auto it:mppy)
    {
        sort(it.second.begin(),it.second.end());
        for(ll i=0;i<it.second.size();i++)
        {
            ans=ans+(2*i+1-it.second.size())*(it.second[i]);
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}