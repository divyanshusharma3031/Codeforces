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
    vi a(n,0);
    vi b(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>b[j];
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]>a[i])
        {
            cout<<"No\n";
            return;
        }
    }
    int x=a[0]-b[0];
    ll mx=-1;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,a[i]-b[i]);
    }
    for(int i=0;i<n;i++)
    {
        int w=a[i]-mx;
        if(w<0)
        {
            w=0;
        }
        if(w==b[i])
        {

        }
        else
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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