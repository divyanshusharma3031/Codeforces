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

    ll x;

    cin>>x;

    vi arr(n,0);

    ll s1=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s1+=arr[i];
    }
    vi a(n+1,INT_MIN);
    for(int i=0;i<=n;i++)
    {
        int x=0;
        int j=i;
        ll s=0;
        for(x=0;x<j;x++)
        {
            s+=arr[x];
        }
        a[i]=max(a[i],s);
        x=0;
        while(j<n)
        {
            s+=arr[j];
            s-=arr[x];
            a[i]=max(a[i],s);
            x++;
            j++;
        }
        // cout<<a[i]<<" ";
    }
    // cout<<"\n";
    for(int i=0;i<=n;i++)
    {
        ll mx=INT_MIN;
        for(int j=0;j<=n;j++)
        {
            mx=max(mx,a[j]+min(i,j)*x);
        }
        cout<<mx<<" ";
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