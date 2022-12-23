#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
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
bool sign(int n)
{
    return n >= 0;
}
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
vi getbinary(int n)
{
    vector<int> ans;
    if (n == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (n > 0)
    {
        int rem = n % 2;
        ans.push_back(rem);
        n = n / 2;
    }
    return ans;
}
bool ispossible(string &arr,vector<int> &pref,vector<int> &suff,int zeroes,int mid)
{
    for(int i=0;i<=mid;i++)
    {
        ll left=zeroes;
        left=left-pref[i]-suff[mid-i];
        if(left<=mid)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    string s;
    cin>>s;
    string arr=s;
    int n=s.size();
    int lo=0;
    int hi=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            hi++;
        }
    }
    vector<int> pref;
    int cnt=0;
    ll zeroes=n-hi;
    for(int i=0;i<n;i++)
    {
        if(arr[i]=='0')
        {
            cnt++;
        }
        else
        {
            pref.push_back(cnt);
        }
    }
    pref.push_back(cnt);
    cnt=0;
    vector<int> suff;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]=='0')
        {
            cnt++;
        }
        else
        {
            suff.push_back(cnt);
        }
    }
    suff.push_back(cnt);
    int ans=hi;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(ispossible(arr,pref,suff,zeroes,mid))
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    cout<<ans<<"\n";
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
    return 0;
}