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
    ll k;
    cin>>k;
    string s;
    cin>>s;
    int l=0;
    int mx=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
        {
            l++;
        }
        else
        {
            
            l=0;
        }
        mx=max(l,mx);
    }
    if(mx>=k)
    {
        cout<<"0\n";
        return;
    }
    int c=0;
    int i=0;
    for(i=0;i<k;i++)
    {
        if(s[i]=='B')
        {
            c++;
        }
    }
    int j=k;
    mx=max(mx,c);
    i=0;
    while(j<n)
    {
        if(s[i]=='B')
        {
            c--;
        }
        i--;
        if(s[j]=='B')
        {
            c++;
        }
        j++;
        mx=max(mx,c);
    }
    cout<<k-mx<<"\n";
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