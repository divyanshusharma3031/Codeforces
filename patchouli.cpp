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
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll e=0;
    ll o=0;
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            o++;
        }
        else
        {
            e++;
            mpp[arr[i]%10]++;
        }
    }
    if(e==0)
    {
        cout<<"0\n";
        return;
    }
    ll c2=mpp[2];
    ll c4=mpp[4];
    ll c6=mpp[6];
    ll c8=mpp[8];
    ll c10=mpp[10];
    ll extra=c2+c6+c10;
    ll ans=0;
    if(c8<=extra)
    {
        ans=ans+c8*2;
        extra=extra-c8;
        c8=0;
    }
    else
    {
        ans=ans+(extra)*2+(c8-extra)*3;
        c8=c8-extra;
        extra=0;
    }
    ans=extra+c4*2;
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