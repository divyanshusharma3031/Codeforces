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
    if(n%2==1)
    {
        if(x%2==0)
        {
            cout<<"No\n";
        }
        else
        {
            if((n-x)>=2)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
    }
    else
    {
        if((n-x)>=1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"No\n";
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