#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

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
    
    cin>>n;
    
    vector<ll> arr(n,0);
    
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l=1;
    if(n==1)
    {
        cout<<"YES\n";
        return;
    }
    int x=arr[n-1];
    int y=arr[n-2];
    for(int i=n-3;i>=0;)
    {
        if(arr[i]<=x && arr[i]<=y)
        {
            if((i-1)>=0)
            {
                if(arr[i-1]<=x && arr[i-1]<=y)
                {
                    x=arr[i];
                    y=arr[i-1];
                }
                else
                {
                    cout<<"NO\n";
                    return;
                }
            }
        }
        else
        {
            cout<<"NO\n";
            return;
        }
        i=i-2;
    }
    cout<<"YES\n";
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