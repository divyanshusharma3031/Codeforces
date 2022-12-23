#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
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
    cin>>n;
    vi arr(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    map<int,int> mpp;

    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    int s=0;
    int d=0;

    for(auto it:mpp)
    {
        if(it.second==1)
        {
            s++;
        }
        else if(it.second>1)
        {
            d++;
        }
    }
    int ans=d+(s+1)/2;
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