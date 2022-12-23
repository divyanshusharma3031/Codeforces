#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
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

void solve()
{
    ll n;

    cin >> n;

    vector<ll> arr(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    if(n==1)
    {
        cout<<1<<"\n1\n";
        cout<<arr[1]<<"\n\n";
        return;
    }
    vector<bool> leaf(n+1,true);
    leaf[0]=false;

    for( ll i=1;i<=n;i++)
    {
        leaf[arr[i]]=false;
    }

    vector<ll> leafnodes;

    for(int i=1;i<=n;i++)
    {
        if(leaf[i]==true)
        {
            leafnodes.push_back(i);
        }
    }
    map<ll,ll> vis;
    vector<vector<int>> paths;
    for(int i=0;i<leafnodes.size();i++)
    {
        // cout<<leafnodes[i]<<" ";
        vector<int> v;
        v.push_back(leafnodes[i]);
        vis[leafnodes[i]]=1;
        ll p=arr[leafnodes[i]];
        while(vis[p]==0)
        {
            v.push_back(p);
            vis[p]=1;
            if(p==arr[p])
            {
                vis[arr[p]]=1;
                break;
            }
            p=arr[p];
        }
        reverse(v.begin(),v.end());
        if(v.size()==0)
        {
            continue;
        }
        paths.push_back(v);
    }
    cout<<paths.size()<<"\n";
    for(int i=0;i<paths.size();i++)
    {
        cout<<paths[i].size()<<"\n";
        for(int j=0;j<paths[i].size();j++)
        {
            cout<<paths[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
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