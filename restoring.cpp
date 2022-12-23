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
    cin >> n;
    vi s(n,0);
    vi f(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    vi d(n,0);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({s[i],f[i]});
    }
    d[0]=f[0]-s[0];
    for(int i=1;i<n;i++)
    {
        if(f[i-1]<=s[i])
        {
            d[i]=f[i]-s[i];
        }
        else
        {
            d[i]=f[i]-f[i-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<d[i]<<" ";
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