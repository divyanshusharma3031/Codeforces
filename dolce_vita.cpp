#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

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
    
    vector<ll> arr(n,0);

    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    vector<ll> pre(n,0);

    pre[0]=arr[0];

    for(ll i=1;i<n;i++)
    {
        pre[i]=arr[i]+pre[i-1];
    }

    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        if(pre[i-1]<=x)
        {
            // pre[i-1]+i*d=x
            //d=(x-pre[i-1])/i;
            ll d=(x-pre[i-1])/i;
            ans=ans+d+1;
        }
        else
        {
            break;
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