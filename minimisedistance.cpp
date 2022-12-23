#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define int long long

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

bool sign(int n)
{
    return n>=0;
}

void solve()
{
    ll n;

    cin >> n;

    ll k;

    cin >> k;

    vi arr(n, 0);

    vector<int> v1;

    vector<int> v2;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>=0)
        {
            v1.push_back(arr[i]);
        }
        else
        {
            v2.push_back(abs(arr[i]));
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int m1=0;
    if(v2.size()>=1)
        m1=v2[v2.size()-1];
    
    int m2=0;

    if(v1.size()>=1)
        m2=v1[v1.size()-1];

    int m3=max(m1,m2);
    int s=0;
    int x=v1.size();
    for(int i=x-1;i>=0;i-=k)
    {
        s+=2*v1[i];
    }
    int c=0;
    int m=v2.size();
    for(int i=m-1;i>=0;i=i-k)
    {
        s+=2*v2[i];
    }
    cout<<s-m3<<"\n";
}
int32_t main()
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