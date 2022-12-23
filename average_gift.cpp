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

void reverse(ll lo, ll hi, vector<ll> &a)
{
    while (lo <= hi)
    {
        swap(a[lo], a[hi]);
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
    ll x;
    cin>>n>>x;
    vi a(n,0);
    
    bool b=false;
    
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==x)
        {
            b=true;   
        }
    }
    sort(a.begin(),a.end());
    ll mini=a[0];
    ll maxi=a[n-1];
    if(x>=mini && x<=maxi)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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