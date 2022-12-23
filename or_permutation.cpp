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
    int n;
    cin>>n;
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

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[a[i]|b[i]]++;
    }
    if(mpp.size()>1)
    {
        cout<<"-1\n";
        return;
    }
    int x;
    for(auto it:mpp)
    {
        x=it.first;
    }
    cout<<x<<"\n";
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