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
    ll m;
    cin>>n>>m;

    vector<vector<ll>> arr(n,vector<ll>(m,0));

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<vector<ll>> arr2=arr;

    for(int i=0;i<n;i++)
    {
        sort(arr2[i].begin(),arr2[i].end());
    }

    map<ll,ll> mpp;

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(arr[i][j]!=arr2[i][j])
            {
                mpp[j]++;
            }
        }
    }
    if(mpp.size()==0)
    {
        cout<<"1 1\n";
        return;
    }
    if(mpp.size()>2)
    {
        cout<<"-1\n";
        return;
    }

    vector<int> v;

    for(auto it:mpp)
    {
        v.push_back(it.first);
    }

    for(int i=0;i<n;i++)
    {
        swap(arr[i][v[0]],arr[i][v[1]]);
    }

    bool b=false;

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(arr[i][j]!=arr2[i][j])
            {
                b=true;
            }
        }
    }
    if(b)
    {
        cout<<"-1\n";
        return;
    }
    cout<<v[0]+1<<" "<<v[1]+1<<"\n";
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