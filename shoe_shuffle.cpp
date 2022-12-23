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
    for(ll  i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }

    bool b=false;
    for(auto it:mpp)
    {
        if(it.second==1)
        {
            b=true;
            break;
        }
    }
    if(b)
    {
        cout<<"-1\n";
        return;
    }
    vector<int> ans;
    for(int i=0;i<n;)
    {
        int v=mpp[arr[i]];
        ans.push_back(v+i);
        for(int j=i+1;j<=(v+i)-1;j++)
        {
            ans.push_back(j);
        }
        i+=mpp[arr[i]];
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
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