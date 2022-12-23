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
    ll k;
    cin >> k;
    string s;
    cin >> s;
    ll ans = 0;
    ll o=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            o++;
        }
    }
    int x = -1;
    int idx=n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            idx=i;
            break;
        }
    }
    ll add=0;
    if(k>=(n-1-idx) && o!=0)
    {
        o--;
        add+=1;
        k=k-n+1+idx;
    }
    idx=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            idx=i;
            break;
        }
    }
    if(k>=(idx) && idx!=(n-1) && o!=0)
    {
        o--;
        add+=10;
    }
    ans=o*11+add;
    cout << ans << "\n";
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