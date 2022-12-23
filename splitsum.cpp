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
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll s=0;
    for(ll i=0;i<n;i++)
    {
        s+=arr[i];
    } 
    ll s1=0;
    for(ll i=0;i<n;i++)
    {
        s1+=arr[i];
        ll x=s&(s-s1);
        if(x!=0)
        {
            cout<<1<<" "<<i+1<<"\n";
            cout<<i+2<<" "<<n<<"\n";
            return;
        }
    }
    
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