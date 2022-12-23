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
    ll y;
    cin>>y;//end mai jo number mila
    vi arr(n,0);
    for( ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll s=0;

    for(ll i=0;i<n;i++)
    {
        s=s+arr[i];
    }
    if(s%2==0)
    {
        if(x%2==y%2)
        {
            cout<<"Alice\n";
        }
        else
        {
            cout<<"Bob\n";
        }
    }
    else
    {
        if(x%2==y%2)
        {
            cout<<"Bob\n";
        }
        else
        {
            cout<<"Alice\n";
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