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
    vi arr(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n==3)
    {
        if(arr[1]%2==0)
        {
            cout<<arr[1]/2<<"\n";
            return;
        }
        else
        {
            cout<<"-1\n";
        }
        return;
    }
    int o=0;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]==1)
        {
            o++;
        }
    }
    if(o==n-2)
    {
        cout<<"-1\n";
        return;
    }
    ll ans=0;
    for(int i=1;i<n-1;i++)
    {
        ans=ans+(arr[i]+1)/2;
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