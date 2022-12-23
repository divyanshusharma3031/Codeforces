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

void solve()
{
    ll n;
    ll m;
    cin>>n>>m;
    vi a(n,0);
    vi b(m,0);

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(ll i=0;i<m;i++)
    {
        cin>>b[i];
    }

    // 1 1 1
    // 3
    if(n!=m)
    {
        cout<<"Alice\n";
        return;
    }
    else
    {
       ll s1=0;
       ll s2=0;
       for(ll i=0;i<n;i++)
       {
           s1+=a[i];
       }
       for(ll i=0;i<m;i++)
       {
           s2+=b[i];
       }
       if(s1!=s2)
       {
           cout<<"Alice\n";
           return;
       }
       else
       {
           sort(a.begin(),a.end());
           sort(b.begin(),b.end());
           bool bo=false;
           for(ll i=0;i<min(n,m);i++)
           {
               if(a[i]!=b[i])
               {
                   bo=true;
               }
           }
           if(bo)
           {
               cout<<"Alice\n";
           }
           else
           {
               cout<<"Bob\n";
           }
       }
    }
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