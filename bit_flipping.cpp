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
    
    ll k;
    
    cin>>n>>k;
    
    string s;
    
    cin>>s;

    vector<ll> v(n,0);

    ll t=k;

    for(ll i=0;i<n;i++)
    {
        if(t<=0)
        {
            break;
        }
        if((k%2)==(s[i]-'0'))
        {
            v[i]=1;
            t--;
        }

    }
    v[n-1]+=t;
    for(int i=0;i<n;i++)
    {
        if((k-v[i])%2==1)
        {
            s[i]='1'-(s[i]-'0');
        }
    }
    cout<<s<<"\n";
    for(ll i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
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